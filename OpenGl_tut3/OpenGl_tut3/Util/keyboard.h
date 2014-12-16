#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QKeyEvent>
#include <QDebug>

class Keyboard
{
public:
    Keyboard();
    static bool SPACE;
    static bool CTRL;
    static bool SHIFT;
    static bool ALT;
    static bool P;
    static bool F;
    static bool L;
    static bool T;

    static void keyPress(QKeyEvent *ev);
    static void keyRelease(QKeyEvent *ev);
};

#endif // KEYBOARD_H
