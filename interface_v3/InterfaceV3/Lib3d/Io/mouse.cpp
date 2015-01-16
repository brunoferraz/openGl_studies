#include "mouse.h"
#include <interface.h>
#include <QDebug>

Mouse::Mouse()
{
}
void Mouse::setPos(float _x, float _y)
{
    lastPosX = x;
    lastPosY = y;
    x = _x;
    y = _y;
    velX = x - lastPosX;
    velY = y - lastPosY;
}

void Mouse::mouseMove(QMouseEvent *ev)
{
    Mouse::setPos(ev->x(),ev->y());
    lastOverIndex   = overIndex;
    overIndex       = colorPicking();
    if(overIndex > Interface::currentDisplayList->length()) overIndex = -1;
    Interface::mouseMove();
    if(lastOverIndex != overIndex){
        if(overIndex == -1){
            Interface::mouseOut();
        }else{
            if(lastOverIndex!=-1){
                Interface::mouseOut();
            }
            Interface::mouseOver();
        }
    }
}

void Mouse::mousePress(QMouseEvent *ev)
{
   Mouse::setPos(ev->x(), ev->y());
   switch(ev->button()){
    case Mouse::BUTTON_LEFT:
       Mouse::button_left = true;
       break;
   case Mouse::BUTTON_RIGHT:
       Mouse::button_right = true;
      break;
   case Mouse::BUTTON_MIDDLE:
       Mouse::button_middle = true;
      break;
   default:
       break;
   }
   Interface::mousePress();
   Interface::canvas->paintGL();
}
void Mouse::mouseRelease(QMouseEvent *ev)
{
    Mouse::setPos(ev->x(), ev->y());
    switch(ev->button()){
     case Mouse::BUTTON_LEFT:
        Mouse::button_left = false;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::button_right = false;
       break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::button_middle = false;
       break;
    default:
        break;
    }
    if(overIndex!= -1){
        Interface::mouseRelease();
        Interface::canvas->paintGL();
    }
}

int Mouse::colorPicking()
{
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    Interface::setRenderMode(Interface::SELECT);
    Interface::canvas->paintGL();
    GLint viewport[4];
    GLubyte pixel[3];

    glGetIntegerv(GL_VIEWPORT,viewport);

    glReadPixels(Mouse::x ,viewport[3]-Mouse::y,1,1,
    GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);
    qDebug() <<pixel[0] << " " << pixel[1] << " " << pixel[2];
    int next = TypeCast::colorToIndex(pixel[0], pixel[1], pixel[2]) -1;

    glEnable(GL_DITHER);
    glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL)
    Interface::setRenderMode(Interface::RENDER);
    Interface::canvas->paintGL();
    return next;
}
bool Mouse::button_left     = false;
bool Mouse::button_right    = false;
bool Mouse::button_middle   = false;
float Mouse::velX           = 0;
float Mouse::velY           = 0;
float Mouse::lastPosX       = 0;
float Mouse::lastPosY       = 0;
float Mouse::x              = 0;
float Mouse::y              = 0;
int Mouse::overIndex        = -1;
int Mouse::lastOverIndex    = -1;
