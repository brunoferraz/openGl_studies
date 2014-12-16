#include "keyboard.h"

Keyboard::Keyboard()
{
}

void Keyboard::keyPress(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_Space:
        Keyboard::SPACE     = true;
        break;
    case Qt::Key_Control:
        Keyboard::CTRL      = true;
        break;
    case Qt::Key_Shift:
        Keyboard::SHIFT     = true;
        break;
    case Qt::Key_Alt:
        Keyboard::ALT       = true;
        break;
    case Qt::Key_L:
        Keyboard::L         = true;
        break;
    case Qt::Key_F:
        Keyboard::F         = true;
        break;
    case Qt::Key_P:
        Keyboard::P         = true;
        break;
    case Qt::Key_T:
        Keyboard::T         = true;
        break;
    default:
        qDebug() << "Need to configure this key on keyboard class ->" << ev->key();
        break;
    }
}

void Keyboard::keyRelease(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_Space:
        Keyboard::SPACE = false;
        break;
    case Qt::Key_Control:
        Keyboard::CTRL  = false;
        break;
    case Qt::Key_Shift:
        Keyboard::SHIFT = false;
        break;
    case Qt::Key_Alt:
        Keyboard::ALT   = false;
        break;
    case Qt::Key_L:
        Keyboard::L     = false;
        break;
    case Qt::Key_F:
        Keyboard::F     = false;
        break;
    case Qt::Key_P:
        Keyboard::P     = false;
        break;
    case Qt::Key_T:
        Keyboard::T     = false;
        break;
    default:
        qDebug() << "Need to configure this key on keyboard class ->" << ev->key();
        break;
    }
}
bool Keyboard::SPACE  = false;
bool Keyboard::CTRL   = false;
bool Keyboard::SHIFT  = false;
bool Keyboard::ALT    = false;
bool Keyboard::P      = false;
bool Keyboard::F      = false;
bool Keyboard::L      = false;
bool Keyboard::T      = false;
