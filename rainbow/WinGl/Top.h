//$ class TopWindow {
private:
	TopWindowFrame *frame;
	
	void SyncRect();
	void SyncFrameRect(const Rect& r);
	void DestroyFrame();
	
	friend class Ctrl;
	bool painting;

public:
	void GripResize();
//$ };