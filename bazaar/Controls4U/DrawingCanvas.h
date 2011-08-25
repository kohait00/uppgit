#ifndef _Controls4U_DrawingCanvas_h_
#define _Controls4U_DrawingCanvas_h_

class Svg2DTransform {
public:
	Svg2DTransform() 						{Init();}
	Svg2DTransform(Svg2DTransform &transf) 	{*this = transf;}
	void Init() {
		transX = transY = 0;
		angle = 0;
		scaleX = scaleY = 1;
	}
	void Apply(Painter &sw) {
		sw.End();
		sw.Begin();
		sw.Translate(transX, transY);
		sw.Scale(scaleX, scaleY);
		sw.Rotate(angle);
	}
	void Translate(double x, double y) {
		transX += x;
		transY += y;
	}
	void Scale(double x, double y) {
		scaleX *= x;
		scaleY *= y;
	}
	void Rotate(double ang) {
		angle += ang;
	}
	Svg2DTransform &operator=(const Svg2DTransform &transf) {
		if (this == &transf)      // Same object?
      		return *this; 
		transX = transf.transX;
		transY = transf.transY;
		angle = transf.angle;
		scaleX = transf.scaleX;
		scaleY = transf.scaleY;
		return *this;
	}
	Svg2DTransform &operator+=(const Svg2DTransform &transf) {
		if (this == &transf)      // Same object?
      		return *this; 
		transX += transf.transX;
		transY += transf.transY;
		angle += transf.angle;
		scaleX *= transf.scaleX;
		scaleY *= transf.scaleY;
		return *this;
	}
	Svg2DTransform &SetTranslate(double x, double y) {
		transX = x;
		transY = y;
		return *this;
	}
	Svg2DTransform &SetScale(double x, double y) {
		scaleX = x;
		scaleY = y;
		return *this;
	}
	Svg2DTransform &SetRotate(double a) {
		angle = a;
		return *this;
	}

private:
	double transX;
	double transY;
	double angle;
	double scaleX;
	double scaleY;
};

class SvgStyle {
public:
	SvgStyle()					{Init();}
	SvgStyle(SvgStyle &transf)  {*this = transf;}
	void Init() {
		strokeWidth = Null;
		strokeFill = Null;
		strokeColor = Null;
		strokeOpacity = Null;
	}
	void Set(String str);
	void Apply(Painter &sw);
	SvgStyle &operator=(const SvgStyle &style);
	SvgStyle &operator+=(const SvgStyle &style);
	
	SvgStyle &SetStrokeWidth(int c) 	 {strokeWidth = c;		return *this;}
	SvgStyle &SetStrokeFill(Color c) 	 {strokeFill = c;		return *this;}
	SvgStyle &SetStrokeColor(Color c) 	 {strokeColor = c;		return *this;}
	SvgStyle &SetStrokeOpacity(double c) {strokeOpacity = c;	return *this;}
		
public:
	int strokeWidth;
	Color strokeFill;
	Color strokeColor;
	double strokeOpacity;
};

class GraphElemLimits : public Rectf {
public:
	GraphElemLimits() {
		Reset();
	}
	void Reset() {
		left = top = -DOUBLE_NULL_LIM;
		right = bottom = DOUBLE_NULL_LIM;
	}
	void UpdateLimits(const Pointf &p) {
		UpdateLimitsH(p.x);
		UpdateLimitsV(p.y);
	}
	void UpdateLimitsH(double x) {
		if (x > right)
			right = x;
		if (x < left)
			left = x;
	}
	void UpdateLimitsV(double y) {
		if (y > bottom)
			bottom = y;
		if (y < top)
			top = y;
	}
	void Cubic(const Pointf& p1, const Pointf& p2, const Pointf& p, bool rel) {
		/*DoMove0();
		CubicData& m = PathAdd<CubicData>(CUBIC);
		m.p1 = PathPoint(p1, rel);
		ccontrol = m.p2 = PathPoint(p2, rel);
		m.p = EndPoint(p, rel);*/
		//UpdateLimits(p1);
		UpdateLimits(p2);
		UpdateLimits(p);
	}
};

class GraphElem {
public:
	Svg2DTransform transf;
	SvgStyle style;
	GraphElemLimits limits;
	
	virtual void Paint(Painter &sw, Svg2DTransform transf, SvgStyle style, bool firstLayer) {};
	virtual void SetLimits() {};
	virtual void PaintLimits(Painter &sw) {
		if (limits == GraphElemLimits())
			return;
		
		sw.Rectangle(limits.left, limits.top, limits.GetWidth(), limits.GetHeight())
					.Opacity(0.3).Stroke(0.5, Black()).Fill(LtBlue());
		sw.Move(limits.left,  limits.top);
		sw.Line(limits.right, limits.bottom).Opacity(0.3).Stroke(0.5, Black());
		sw.Move(limits.right, limits.top);
		sw.Line(limits.left,  limits.bottom).Opacity(0.3).Stroke(0.5, Black());
	}
	virtual ~GraphElem() {};
};


class LineElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf += transf;
		_transf.Apply(sw);	
		sw.Move(x1, y1);
		sw.Line(x2, y2);	
		_style += style;	
		_style.Apply(sw);
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.left = x1;
		limits.top = y1;
		limits.right = x2;
		limits.bottom = y2;
	}
	LineElem(double x1, double y1, double x2, double y2) : x1(x1), x2(x2), y1(y1), y2(y2) {SetLimits();}
	LineElem() {x1 = x2 = y1 = y2 = 0;}
	
//private:
	double x1, y1, x2, y2;
};

class RectElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf += transf;
		_transf.Apply(sw);	
		sw.Rectangle(x, y, width, height);		
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.left = x;
		limits.top = y;
		limits.right = x + width;
		limits.bottom = y + height;
	}
	RectElem(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {SetLimits();}
	RectElem() {x = y = width = height = 0;}

//private:
	double x, y, width, height;
};	

class EllipseElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf += transf;
		_transf.Apply(sw);	
		sw.Ellipse(x, y, width, height);		
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.left = x - width;
		limits.top = y - height;
		limits.right = x + width;
		limits.bottom = y + height;
	}
	EllipseElem(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {SetLimits();} 
	EllipseElem() {x = y = width = height = 0;}

//private:
	double x, y, width, height;
};
	
class ImageElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		if (IsNull(img))
			img = StreamRaster::LoadFileAny(fileName);
		_transf += transf;
		_transf.Apply(sw);	
		sw.Rectangle(x, y, width, height).Fill(img, x, y, width, 0).Stroke(0, Black());
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.left = x;
		limits.top = y;
		limits.right = x + width;
		limits.bottom = y + height;
	}
	ImageElem(double x, double y, double width, double height, String fileName) : x(x), y(y), 
					width(width), height(height), fileName(fileName) {img = Null; SetLimits();}
	ImageElem() {x = y = width = height = 0; img = Null;}

//private:
	double x, y, width, height;
	String fileName;
	Image img;
};	

class PolygonElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf += transf;
		_transf.Apply(sw);	
		sw.Move(points[0].x, points[0].y);
		for (int i = 1; i < points.GetCount(); ++i)				
			sw.Line(points[i].x, points[i].y);
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.Reset();
		for (int i = 0; i < points.GetCount(); ++i) 
			limits.UpdateLimits(points[i]);
	}
	PolygonElem() {}

//private:
	Array<Pointf> points;
};	

class TextElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf.Translate(x, y-f.GetHeight()/factor);
		_transf.Scale(1./factor, 1./factor);						
		_transf += transf;
		_transf.Apply(sw);	
		sw.Text(0, 0, text, f);
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	virtual void SetLimits() {
		limits.left = 0;
		limits.top = 0;
		
		FontInfo fi = f.Info();
		limits.right = limits.left;
		WString wtext(text);
		for (int i = 0; i < wtext.GetCount(); ++i) 
			limits.right += fi[wtext[i]];
		limits.bottom = limits.top + f.GetHeight();
	}
	TextElem() {	
		factor = 20;
		f.Face(Font::ARIAL);
		f.Height(12);
	}

//private:
	double x, y;
	String text;
	String font;
	Font f;
	int factor;
};

class PathElem : public GraphElem {
public:
	virtual void Paint(Painter &sw, Svg2DTransform _transf, SvgStyle _style, bool) {
		_transf += transf;
		_transf.Apply(sw);	
		if (!path.IsEmpty())
			sw.Path(path);		
		_style += style;	
		_style.Apply(sw);	
		PaintLimits(sw);
	}
	bool ReadBool(CParser& p) {		// Painter::
		while(p.Char(','));
		if(p.Char('1')) return true;
		p.Char('0');
		return false;
	}
	double ReadDouble(CParser& p) {		// Painter::
		while(p.Char(','));
		return p.IsDouble() ? p.ReadDouble() : 0;
	}
	Pointf ReadPoint(CParser& p) {		// Painter::
		Pointf t;
		t.x = ReadDouble(p);
		t.y = ReadDouble(p);
		return t;
	}
	virtual void SetLimits() {
		CParser p(path);
		limits.Reset();
		while(!p.IsEof()) {
			int c = p.GetChar();
			p.Spaces();
			bool rel = IsLower(c);
			Pointf t, t1, t2;
			switch(ToUpper(c)) {
			case 'M':
				t = ReadPoint(p);
				//Move(t, rel);
				limits.UpdateLimits(t);
			case 'L':
				while(p.IsDouble()) {
					t = ReadPoint(p);
					//Line(t, rel);
					limits.UpdateLimits(t);
				}
				break;
			case 'Z':
				//Close();
				break;
			case 'H':
				while(p.IsDouble())
					//Line(p.ReadDouble(), Null, rel);
					limits.UpdateLimitsH(p.ReadDouble());
				break;
			case 'V':
				while(p.IsDouble())
					//Line(Null, p.ReadDouble(), rel);
					limits.UpdateLimitsV(p.ReadDouble());
					;
				break;
			case 'C':
				while(p.IsDouble()) {
					t1 = ReadPoint(p);
					t2 = ReadPoint(p);
					t = ReadPoint(p);
					limits.Cubic(t1, t2, t, rel);
					//Cubic(t1, t2, t, rel);
				}
				break;
			case 'S':
				while(p.IsDouble()) {
					t2 = ReadPoint(p);
					t = ReadPoint(p);
					//Cubic(t2, t, rel);
					//limits.UpdateLimits(t2);
					limits.UpdateLimits(t);
				}
				break;
			case 'Q':
				while(p.IsDouble()) {
					t1 = ReadPoint(p);
					t = ReadPoint(p);
					//Quadratic(t1, t, rel);
					//limits.UpdateLimits(t1);
					limits.UpdateLimits(t);
				}
				break;
			case 'T':
				while(p.IsDouble()) {
					t = ReadPoint(p);
					//Quadratic(t, rel);
					limits.UpdateLimits(t);
				}
				break;
			case 'A':
				while(p.IsDouble()) {
					t1 = ReadPoint(p);
					double xangle = ReadDouble(p);
					bool large = ReadBool(p);
					bool sweep = ReadBool(p);
					t = ReadPoint(p);
					//SvgArc(t1, xangle * M_PI / 180.0, large, sweep, t, rel);
				}
				break;
			default:
				return;
			}
		}
	}
	PathElem() {}

//private:
	String path;
};
		

class GraphElemList : public GraphElem {
public:
	Array<GraphElem> elems;

	String title;

	void Paint(Painter &sw, Svg2DTransform transf, SvgStyle style, bool firstLayer = false);
	void Clear();
};


class CanvasSelector {
typedef CanvasSelector CLASSNAME;		
public:	
	
};

class DrawingCanvas : public Ctrl {
typedef DrawingCanvas CLASSNAME;		
public:	
	DrawingCanvas();

	GraphElemList elemList;
		
protected:
	virtual void Paint(Draw& draw);	
	
private:
	double translateX, translateY;
	double rotate;
	double scale;
	bool transparent;
	double opacity;
	int linejoin, linecap;
	int quality;
	double scaleFactor;
	
	void DoPaint(Painter& sw);
	
	virtual void MouseMove(Point p, dword keyflags);
	virtual void MouseWheel(Point p, int zdelta, dword keyflags);
	virtual void MiddleDown(Point p, dword keyflags);
	virtual void MiddleUp(Point p, dword keyflags);
	virtual void MouseLeave();
	struct FocusMove {
		bool focusMoving;
		Point lastFocusPoint;
	} focusMove;
	
	virtual void LeftDown(Point p, dword keyflags);
	virtual void LeftUp(Point p, dword keyflags);
	struct SelectionWindow {
		bool isSelected;
		Rect selected;
	} selectionWindow;
};

bool LoadSvg(DrawingCanvas &canvas, String fileName);

	
#endif
