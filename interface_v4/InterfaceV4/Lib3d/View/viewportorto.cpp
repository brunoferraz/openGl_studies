#include "viewportorto.h"

ViewPortOrto::ViewPortOrto()
{

}

void ViewPortOrto::configProjection()
{
    info.near       = -100.1;
    info.far        = 100;
    float ratio     = info.viewPort_width/info.viewPort_height;
    glOrtho(-ratio, ratio, -1, 1, -10.1, 10);
//    gluOrtho2D(-ratio, ratio, -1, 1 );
}

void ViewPortOrto::configModelView()
{

}

void ViewPortOrto::applyTransform()
{

}
