#include "interface.h"

Interface::Interface()
{

}

void Interface::mouseWheelEvent(QWheelEvent *ev)
{
    CameraSet::mouseWheel(ev);
    canvas->update();
}

void Interface::MouseMove(QMouseEvent *ev)
{
    if(bCamera || Keyboard::CTRL){ //if BUTTON_CAMERA is pressed
        Mouse::setPos(ev->x(), ev->y());
        CameraSet::mouseMove(ev);
        canvas->update();
    }
}

void Interface::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
}

void Interface::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
}

void Interface::KeyboardPressEvent(QKeyEvent *ev)
{
    Keyboard::keyPress(ev);
    CameraSet::keyBoardEvent();
}

void Interface::KeyboardReleaseEvent(QKeyEvent *ev)
{
    Keyboard::keyRelease(ev);
}

QLabel*                 Interface::viewPortLabel;
bool                    Interface::bCamera = false;
bool                    Interface::bShape  = false;
Glwidget*               Interface::canvas;
QList<QPushButton>      Interface::buttonList;
