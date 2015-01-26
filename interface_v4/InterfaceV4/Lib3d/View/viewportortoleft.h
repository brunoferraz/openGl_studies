#ifndef VIEWPORTORTOLEFT_H
#define VIEWPORTORTOLEFT_H

#include <View/viewportorto.h>

class ViewPortOrtoLeft : public ViewPortOrto
{
public:
    ViewPortOrtoLeft();

    void configProjection();
    Eigen::Vector3f getTranslateFromScreen(float x, float y);
};

#endif // VIEWPORTORTOLEFT_H
