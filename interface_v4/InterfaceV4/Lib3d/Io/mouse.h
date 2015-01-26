#ifndef MOUSE_H
#define MOUSE_H

#include <QMouseEvent>

class Mouse
{
public:
    Mouse();

    static int const LEFT   = 1;
    static int const MIDDLE = 4;
    static int const RIGHT  = 2;

    static int x;
    static int y;
    static int lastX;
    static int lastY;

    static float velX;
    static float velY;

    static bool mouse_left;
    static bool mouse_middle;
    static bool mouse_right;

    static int overIndex;
    static int lastOverIndex;

    static void setPos(QMouseEvent *ev);

    static void mousePress(QMouseEvent *ev);
    static void mouseRelease(QMouseEvent *ev);
    static void mouseMove(QMouseEvent *ev);

    static void colorPicking();
};

#endif // MOUSE_H
