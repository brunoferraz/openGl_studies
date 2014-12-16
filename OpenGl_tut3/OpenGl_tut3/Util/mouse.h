#ifndef MOUSE_H
#define MOUSE_H

#include <QDebug>
#include <stdio.h>
#include <QMouseEvent>


using namespace std;
class Mouse
{
public:
    Mouse();
    static float lastX;
    static float lastY;
    static float x;
    static float y;
    static float velX;
    static float velY;
    static void setPos(int nx, int ny);

    static const int BUTTON_LEFT = 1;
    static const int BUTTON_RIGHT = 2;
    static const int BUTTON_MIDDLE = 4;

    static bool LEFT;
    static bool MIDDLE;
    static bool RIGHT;

    static void mouseMove(QMouseEvent *ev);
    static void mousePress(QMouseEvent *ev);
    static void mouseRelease(QMouseEvent *ev);
};

#endif // MOUSE_H
