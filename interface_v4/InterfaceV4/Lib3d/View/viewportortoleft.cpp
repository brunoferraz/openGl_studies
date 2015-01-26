#include "viewportortoleft.h"

ViewPortOrtoLeft::ViewPortOrtoLeft()
{
}

void ViewPortOrtoLeft::configProjection()
{
    ViewPortOrto::configProjection();
    rotate(90, 0, 1, 0);
}

Eigen::Vector3f ViewPortOrtoLeft::getTranslateFromScreen(float x, float y)
{
    Eigen::Vector3f nPos;
    nPos << 0.0, -y, x;
    return nPos;
}
