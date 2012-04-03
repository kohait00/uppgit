#include "Core.h"

NAMESPACE_UPP

String FormatIP(dword _ip)
{
	byte ip[4];
	Poke32be(ip, _ip);
	return Format("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

static const char hex_digits[] = "0123456789ABCDEF";

String UrlEncode(const String& s)
{
	const char *p = s, *e = s.End();
	String out;
	for(; p < e; p++)
	{
		const char *b = p;
		while(p < e && (byte)*p > ' ' && (byte)*p < 127
		      && (IsAlNum(*p) || *p == '.' || *p == '-' || *p == '_'))
			p++;
		if(p > b)
			out.Cat(b, int(p - b));
		if(p >= e)
			break;
		if(*p == ' ')
			out << '+';
		else
			out << '%' << hex_digits[(*p >> 4) & 15] << hex_digits[*p & 15];
	}
	return out;
}

String UrlEncode(const String& s, const char *specials)
{
	int l = (int)strlen(specials);
	const char *p = s, *e = s.End();
	String out;
	for(; p < e; p++)
	{
		const char *b = p;
		while(p < e && (byte)*p > ' ' && (byte)*p < 127 && memchr(specials, *p, l) == 0)
			p++;
		if(p > b)
			out.Cat(b, int(p - b));
		if(p >= e)
			break;
		if(*p == ' ')
			out << '+';
		else
			out << '%' << hex_digits[(*p >> 4) & 15] << hex_digits[*p & 15];
	}
	return out;
}

String UrlDecode(const char *b, const char *e)
{
	StringBuffer out;
	byte d1, d2, d3, d4;
	for(const char *p = b; p < e; p++)
		if(*p == '+')
			out.Cat(' ');
		else if(*p == '%' && (d1 = ctoi(p[1])) < 16 && (d2 = ctoi(p[2])) < 16) {
			out.Cat(d1 * 16 + d2);
			p += 2;
		}
		else if(*p == '%' && (p[1] == 'u' || p[1] == 'U')
		&& (d1 = ctoi(p[2])) < 16 && (d2 = ctoi(p[3])) < 16
		&& (d3 = ctoi(p[4])) < 16 && (d4 = ctoi(p[5])) < 16) {
			out.Cat(WString((d1 << 12) | (d2 << 8) | (d3 << 4) | d4, 1).ToString());
			p += 5;
		}
		else
			out.Cat(*p);
	return out;
}

String Base64Encode(const char *b, const char *e)
{
	static const char encoder[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";
	if(b == e)
		return Null;
	int out = (int(e - b) + 2) / 3 * 4;
	int rem = int(e - b) % 3;
	e -= rem;
	StringBuffer s(out);
	char *p = s;
	while(b < e)
	{
		p[0] = encoder[(b[0] >> 2) & 0x3F];
		p[1] = encoder[((b[0] << 4) & 0x30) | ((b[1] >> 4) & 0x0F)];
		p[2] = encoder[((b[1] << 2) & 0x3C) | ((b[2] >> 6) & 0x03)];
		p[3] = encoder[b[2] & 0x3F];
		b += 3;
		p += 4;
	}
	if(rem == 1)
	{
		p[0] = encoder[(b[0] >> 2) & 0x3F];
		p[1] = encoder[(b[0] << 4) & 0x30];
		p[2] = p[3] = '=';
	}
	else if(rem == 2)
	{
		p[0] = encoder[(b[0] >> 2) & 0x3F];
		p[1] = encoder[((b[0] << 4) & 0x30) | ((b[1] >> 4) & 0x0F)];
		p[2] = encoder[(b[1] << 2) & 0x3C];
		p[3] = '=';
	}
	return s;
}

String Base64Decode(const char *b, const char *e)
{
	static byte dec64[] =
	{
/* 0x */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 1x */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 2x */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0xFF, 0xFF, 0xFF, 0x3F,
/* 3x */0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 4x */0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
/* 5x */0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 6x */0xFF, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
/* 7x */0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 8x */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 9x */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Ax */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Bx */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Cx */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Dx */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Ex */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* Fx */0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	};
	StringBuffer out;
	byte c[4];
	int pos = 0;
	for(; b < e; b++)
		if((byte)*b > ' ') {
			byte ch = dec64[(byte)*b];
			if(ch & 0xC0)
				break;
			c[pos++] = ch;
			if(pos == 4) {
				out.Cat((c[0] << 2) | (c[1] >> 4));
				out.Cat((c[1] << 4) | (c[2] >> 2));
				out.Cat((c[2] << 6) | (c[3] >> 0));
				pos = 0;
			}
		}
	if(pos >= 2) {
		out.Cat((c[0] << 2) | (c[1] >> 4));
		if(pos >= 3) {
			out.Cat((c[1] << 4) | (c[2] >> 2));
			if(pos >= 4)
				out.Cat((c[2] << 6) | (c[3] >> 0));
		}
	}
	return out;
}

void HttpHeader::Clear()
{
	first_line.Clear();
	fields.Clear();
}

bool HttpHeader::Parse(const String& hdrs)
{
	StringStream ss(hdrs);
	String s = ss.GetLine();
	first_line = s;
	while(!ss.IsEof()) {
		s = ss.GetLine();
		if(s.IsEmpty()) break;
		int q = s.Find(':');
		if(q >= 0)
			fields.Add(ToLower(s.Mid(0, q))) = TrimLeft(s.Mid(q + 1));
	}
	return true;
}

bool HttpHeader::Request(String& method, String& uri, String& version)
{
	const char *s = first_line;
	if((byte)*s <= ' ')
		return false;
	method.Clear();
	while(*s != ' ' && *s)
		method.Cat(*s++);
	while(*s == ' ')
		s++;
	if(!*s)
		return false;
	uri.Clear();
	while(*s != ' ' && *s)
		uri.Cat(*s++);
	while(*s == ' ')
		s++;
	if(!*s)
		return false;
	version = s;
	return true;
}

bool HttpHeader::Response(String& protocol, int& code, String& reason)
{
	String c;
	if(Request(protocol, c, reason)) {
		code = ScanInt(c);
		return !IsNull(code);
	}
	return false;
}

END_UPP_NAMESPACE