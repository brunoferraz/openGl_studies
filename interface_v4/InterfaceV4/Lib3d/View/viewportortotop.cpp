#include "viewportortotop.h"

ViewPortOrtoTop::ViewPortOrtoTop()
{
}

void ViewPortOrtoTop::configProjection()
{
    ViewPortOrto::configProjection();
    rotate(90, 1, 0, 0);
}
