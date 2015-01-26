#include "viewportortoleft.h"

ViewPortOrtoLeft::ViewPortOrtoLeft()
{
}

void ViewPortOrtoLeft::configProjection()
{
    ViewPortOrto::configProjection();
    rotate(90, 0, 1, 0);
}
