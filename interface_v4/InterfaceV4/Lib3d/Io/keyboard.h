#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QKeyEvent>

class Keyboard
{
public:
    Keyboard();
    static bool Key_ctrl;
    static bool Key_alt;
    static bool Key_shift;

    static bool Key_c;
    static bool Key_a;
    static bool Key_f;
    static bool Key_d;
    static bool Key_p;
    static bool Key_v;
    static bool Key_t;

    static void keyPress(QKeyEvent *ev);
    static void keyRelease(QKeyEvent *ev);
};

#endif // KEYBOARD_H
