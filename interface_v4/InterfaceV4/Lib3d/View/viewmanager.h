#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <View/viewport.h>
#include <View/viewportorto.h>
#include <QList>

class ViewManager
{
public:
    ViewManager();
    static const int PERSPECTIVE = 0;

    static const int TOP         = 1;
    static const int LEFT        = 2;
    static const int FRONT       = 3;

    static const int BOTTOM      = 4;
    static const int RIGHT       = 5;
    static const int BACK        = 6;

    QList<ViewPort *> list;

    float width;
    float height;
    float ratio;
    void setSize(int w, int h);

    ViewPort *currentView;
    void setViewPort(int const i);
};

#endif // VIEWMANAGER_H
