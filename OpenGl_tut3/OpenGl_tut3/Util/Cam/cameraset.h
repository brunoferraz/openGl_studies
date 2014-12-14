#ifndef CAMERASET_H
#define CAMERASET_H

#include <Util/Cam/camera.h>
#include <Util/Cam/cameraortho.h>
#include <QList>
#include <QDebug>
#include <QMouseEvent>
#include <Util/mouse.h>
#include <QWheelEvent>

class CameraSet
{
public:
    CameraSet();

    static Camera* currentCamera;
    static Camera defaultCamera;

    static const int PERSPECTIVE    = 0;
    static const int LEFT           = 1;
    static const int RIGHT          = 2;
    static const int FRONT          = 3;
    static const int BOTTOM         = 4;

    static QList<Camera *> camList;

    static void init();
    static void configScreen(int w, int h);
    static void mousePress(QMouseEvent *ev);
    static void mouseRelase(QMouseEvent *ev);
    static void mouseMove(QMouseEvent *);
    static void mouseWheel(QWheelEvent *ev);
};

#endif // CAMERASET_H
