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
};

#endif // VIEWPORTORTO_H
