#ifndef VIEWPORTORTO_H
#define VIEWPORTORTO_H

#include <View/viewport.h>

class ViewPortOrto : public ViewPort
{
public:
    ViewPortOrto();
    void configProjection();
    void configModelView();
    void applyTransform();

    virtual Eigen::Vector3f getTranslateFromScreen(float x, float y);
};

#endif // VIEWPORTORTO_H
