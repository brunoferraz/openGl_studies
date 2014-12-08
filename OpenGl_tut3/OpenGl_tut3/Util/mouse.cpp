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
float Mouse::x = 0;
float Mouse::y = 0;

float Mouse::lastX =0;
float Mouse::lastY =0;

float Mouse::velX = 0;
float Mouse::velY = 0;

bool Mouse::LEFT    = false;
bool Mouse::RIGHT   = false;
bool Mouse::MIDDLE  = false;
