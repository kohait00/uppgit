#include "Browser.h"

String ReadId(CParser& p, String& rr)
{
	p.Char('(');
	String id = p.ReadId();
	p.Char(',');
	if(p.IsNumber())
		p.ReadNumber();
	p.Char(',');
	if(p.IsNumber())
		p.ReadNumber();
	p.Char(')');
	rr << "SqlId " << id << "(\"" << id << "\");";
	return id;
}

void ScanSchFile(const char *fn)
{
	String s = LoadFile(fn);
	CParser p(s);
	String r, rr;
	int line;
	while(!p.IsEof())
		try {
			line = p.GetLine();
			if(p.Id("TABLE") || p.Id("TABLE_") || p.Id("TYPE") || p.Id("TYPE_"))
				r << "struct S_" << ReadId(p, rr) << " {";
			else
			if(p.Id("END_TABLE") || p.Id("END_TYPE"))
				r << "};";
			else
			if(p.Id("LONGRAW") || p.Id("LONGRAW_") || p.Id("BLOB") || p.Id("BLOB_") ||
			   p.Id("STRING_") || p.Id("STRING") || p.Id("CLOB") || p.Id("CLOB_"))
				r << "\tString " << ReadId(p, rr) << ";";
			else
			if(p.Id("INT") || p.Id("INT_") || p.Id("SERIAL") || p.Id("ISERIAL"))
				r << "\tint " << ReadId(p, rr) << ";";
			else
			if(p.Id("DOUBLE") || p.Id("DOUBLE_"))
				r << "\tdouble " << ReadId(p, rr) << ";";
			else
			if(p.Id("TIME") || p.Id("TIME_"))
				r << "\tTime " << ReadId(p, rr) << ";";
			else
			if(p.Id("DATE") || p.Id("DATE_"))
				r << "\tDate " << ReadId(p, rr) << ";";
			else
			if(p.Id("BIT") || p.Id("BIT_") || p.Id("BOOL") || p.Id("BOOL_"))
				r << "\tbool " << ReadId(p, rr) << ";";
			else
			if(p.Id("INT_ARRAY") || p.Id("INT_ARRAY_"))
				r << "\tint " << ReadId(p, rr) << "[1];";
			else
			if(p.Id("DOUBLE_ARRAY") || p.Id("DOUBLE_ARRAY_"))
				r << "\tdouble " << ReadId(p, rr) << "[1];";
			else
			if(p.Id("TIME_ARRAY") || p.Id("TIME_ARRAY_"))
				r << "\tTime " << ReadId(p, rr) << "[1];";
			else
			if(p.Id("DATE_ARRAY") || p.Id("DATE_ARRAY_"))
				r << "\tDate " << ReadId(p, rr) << "[1];";
			else
			if(p.Id("BOOL_ARRAY") || p.Id("BOOL_ARRAY_") || p.Id("BIT_ARRAY") || p.Id("BIT_ARRAY_"))
				r << "\tbool " << ReadId(p, rr) << "[1];";
			else
			if(p.Id("SEQUENCE") || p.Id("SEQUENCE_"))
				ReadId(p, rr);
			else
				p.SkipTerm();
			line = p.GetLine() - line;
			for(int i = 0; i < line; ++i) {
				r << '\n';
				rr << '\n';
			}
		}
		catch(CParser::Error)
		{}
	StringStream ss(r), sr(rr);
	CppBase& base = CodeBase();
	Parse(sr, IgnoreList(), base, fn, CNULL);
	Parse(ss, IgnoreList(), base, fn, CNULL);
}
