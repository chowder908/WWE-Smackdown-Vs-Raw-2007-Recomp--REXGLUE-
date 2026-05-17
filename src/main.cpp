// wwesmackdownvsraw2007 - ReXGlue Recompiled Project

#include "generated/wwesmackdownvsraw2007_init.h"

#include "wwesmackdownvsraw2007_app.h"

#include <cmath>

extern "C" float roundevenf(float x) {
    // std::rintf uses the default Windows FPU rounding mode, which perfectly mirrors ties-to-even
    return std::rintf(x); 
}

REX_DEFINE_APP(wwesmackdownvsraw2007, Wwesmackdownvsraw2007App::Create)