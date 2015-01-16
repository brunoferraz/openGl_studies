#ifndef MOUSE_H
#define MOUSE_H

#include <QMouseEvent>
#include <Util/typecast.h>

class Mouse
{
public:
    Mouse();
    static int const BUTTON_LEFT    = 1;
    static int const BUTTON_RIGHT   = 2;
    static int const BUTTON_MIDDLE  = 4;

    static bool button_left;
    static bool button_right;
    static bool button_middle;

    static float x;
    static float y;
    static float velX;
    static float velY;
    static float lastPosX;
    static float lastPosY;

    static int overIndex;
    static int lastOverIndex;

    static void setPos(float _x=0, float _y=0);

    static void mouseMove(QMouseEvent *ev);
    static void mousePress(QMouseEvent *ev);
    static void mouseRelease(QMouseEvent *ev);
    static void hitPicking(int x, int y);
    static int colorPicking();
};

#endif // MOUSE_H
