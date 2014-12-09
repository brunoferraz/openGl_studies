#include "mouse.h"

Mouse::Mouse()
{
}

void Mouse::setPos(int nx, int ny)
{
    Mouse::lastX = Mouse::x;
    Mouse::lastY = Mouse::y;

    Mouse::x = nx;
    Mouse::y = ny;

    Mouse::velX = Mouse::x - Mouse::lastX;
    Mouse::velY = Mouse::y - Mouse::lastY;
}

void Mouse::mouseMove(QMouseEvent *ev)
{

}

void Mouse::mousePress(QMouseEvent *ev)
{
    switch (ev->buttons()) {
    case Mouse::BUTTON_LEFT:
        Mouse::LEFT = true;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::RIGHT = true;
        break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::MIDDLE = true;
        break;
    default:
        break;
    }
    Mouse::setPos(ev->x(), ev->y());
}

void Mouse::mouseRelease(QMouseEvent *ev)
{
    switch (ev->button()) {
    case Mouse::BUTTON_LEFT:
        Mouse::LEFT = false;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::RIGHT = false;
        break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::MIDDLE = false;
        break;
    default:
        break;
    }
}
float Mouse::x = 0;
float Mouse::y = 0;

float Mouse::lastX =0;
float Mouse::lastY =0;

float Mouse::velX = 0;
float Mouse::velY = 0;

bool Mouse::LEFT    = false;
bool Mouse::RIGHT   = false;
bool Mouse::MIDDLE  = false;
