#include "CtrlPropCommon.h"
#include <CtrlLib/CtrlLib.h>

bool PropSetInc(const Value& v, EditIntSpin& o) { if(!IsNumber(v)) return false; o.SetInc(v); return true; }
bool PropGetInc(Value& v, const EditIntSpin& o) { v = o.GetInc(); return true; }
bool PropSetShowSpin(const Value& v, EditIntSpin& o) { if(!IsNumber(v)) return false; o.ShowSpin(v); return true; }
bool PropGetShowSpin(Value& v, const EditIntSpin& o) { v = o.IsShowSpin(); return true; }

PROPERTIES(EditIntSpin, EditInt)
PROPERTY("inc", PropSetInc, PropGetInc)
PROPERTY("showspin", PropSetShowSpin, PropGetShowSpin)
END_PROPERTIES

PROPS(Ctrl, EditIntSpin, EditInt)