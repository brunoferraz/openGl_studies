#ifndef CAMERASET_H
#define CAMERASET_H

#include <Util/Cam/camera.h>
#include <Util/Cam/cameraortho.h>
#include <QList>
#include <QDebug>
#include <QMouseEvent>
#include <Util/mouse.h>
#include <QWheelEvent>
#include <QKeyEvent>
#include <Util/keyboard.h>
#include <QGLWidget>
#include <QLabel>

class CameraSet
{
public:
    CameraSet();

    static Camera* currentCamera;
    static Camera defaultCamera;

    //static QGLWidget *canvas;

    static const int PERSPECTIVE = 0;

    static const int TOP         = 1;
    static const int LEFT        = 2;
    static const int FRONT       = 3;

    static const int BOTTOM      = 4;
    static const int RIGHT       = 5;
    static const int BACK        = 6;

    static QList<Camera *> camList;

    static void changeCam(int cam);

    static void init(int w, int h);
    static void configScreen(int w, int h);
    static void mousePress(QMouseEvent *ev);
    static void mouseRelase(QMouseEvent *ev);
    static void mouseMove(QMouseEvent *);
    static void mouseWheel(QWheelEvent *ev);
    static void keyBoardEvent();

};

#endif // CAMERASET_H
