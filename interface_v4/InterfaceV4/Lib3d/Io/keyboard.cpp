#include "keyboard.h"
#include <interface.h>

Keyboard::Keyboard()
{

}

void Keyboard::keyPress(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_Control:
        Key_ctrl = true;
        break;
    case Qt::Key_Shift:
        Key_shift = true;
        break;
    case Qt::Key_C:
        Key_c = true;
        break;
    case Qt::Key_A:
        Key_a = true;
        break;
    case Qt::Key_F:
        Key_f = true;
        break;
    case Qt::Key_D:
        Key_d = true;
        break;
    case Qt::Key_V:
        Key_v = true;
        break;
    case Qt::Key_T:
        Key_t = true;
        break;
    case Qt::Key_P:
        Key_p = true;
        break;
    case Qt::Key_L:
        Key_l = true;
        break;
    default:
        break;
    }
    Interface::keyPress();
}

void Keyboard::keyRelease(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_Control:
        Key_ctrl = false;
        break;
    case Qt::Key_Shift:
        Key_shift = false;
        break;
    case Qt::Key_C:
        Key_c = false;
        break;
    case Qt::Key_A:
        Key_a = false;
        break;
    case Qt::Key_F:
        Key_f = false;
        break;
    case Qt::Key_D:
        Key_d = false;
        break;
    case Qt::Key_P:
        Key_p = false;
        break;
    case Qt::Key_V:
        Key_v = false;
        break;
    case Qt::Key_T:
        Key_t = false;
        break;
    case Qt::Key_L:
        Key_l = false;
        break;
    default:
        break;
    }
    Interface::keyRelease();
}

bool Keyboard::Key_ctrl = false;
bool Keyboard::Key_alt = false;
bool Keyboard::Key_shift= false;

bool Keyboard::Key_c= false;
bool Keyboard::Key_a= false;
bool Keyboard::Key_f= false;
bool Keyboard::Key_d= false;
bool Keyboard::Key_p= false;
bool Keyboard::Key_v= false;
bool Keyboard::Key_t= false;
bool Keyboard::Key_l= false;
