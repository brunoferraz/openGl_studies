#include "viewportortotop.h"

ViewPortOrtoTop::ViewPortOrtoTop()
{
}

void ViewPortOrtoTop::configProjection()
{
    ViewPortOrto::configProjection();
    rotate(90, 1, 0, 0);
}

Eigen::Vector3f ViewPortOrtoTop::getTranslateFromScreen(float x, float y)
{
    Eigen::Vector3f nPos;
    nPos << x, 0, y;
    return nPos;
}
