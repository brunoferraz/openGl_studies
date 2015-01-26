#include "mouse.h"
#include <interface.h>

Mouse::Mouse()
{
}

void Mouse::setPos(QMouseEvent *ev)
{
    lastX = x;
    lastY = y;
    x = ev->x();
    y = ev->y();
    velX = x - lastX;
    velY = y - lastY;
}

void Mouse::mousePress(QMouseEvent *ev)
{
    Mouse::setPos(ev);
    switch (ev->button()) {
    case LEFT:
        mouse_left = true;
        break;
    case MIDDLE:
        mouse_middle = true;
        break;
    case RIGHT:
        mouse_right = true;
        break;
    default:
        break;
    }
    Interface::mousePress();
}

void Mouse::mouseRelease(QMouseEvent *ev)
{
    Mouse::setPos(ev);
    switch (ev->button()) {
    case LEFT:
        mouse_left = false;
        break;
    case MIDDLE:
        mouse_middle = false;
        break;
    case RIGHT:
        mouse_right = false;
        break;
    default:
        break;
    }
    Interface::mouseRelease();
}

void Mouse::mouseMove(QMouseEvent *ev)
{
    Mouse::setPos(ev);
    colorPicking();
    Interface::mouseMove();
    if(Mouse::overIndex!= Mouse::lastOverIndex){
        if(Mouse::lastOverIndex==-1){
        //From none to object
            Interface::mouseOver();
        }else if(Mouse::overIndex==-1){
        //From object to none
            Interface::mouseOut();
        }else{
        //From objetct to object
            Interface::mouseOut();
            Interface::mouseOver();
        }
    }
    Interface::canvas->update();
}

void Mouse::colorPicking()
{
    Interface::setRenderMode(Interface::SELECT);
    Interface::canvas->paintGL();
    GLint viewport[4];
    GLubyte pixel[3];

    glGetIntegerv(GL_VIEWPORT,viewport);

    glReadPixels(Mouse::x ,viewport[3]-Mouse::y,1,1,
    GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);
//    qDebug() <<pixel[0] << " " << pixel[1] << " " << pixel[2];
    int next = TypeCast::colorToIndex(pixel[0], pixel[1], pixel[2]) -1;

    Mouse::lastOverIndex = Mouse::overIndex;
    Mouse::overIndex = next;

    Interface::setRenderMode(Interface::RENDER);
    //Interface::canvas->paintGL();
}

int Mouse::x = 0;
int Mouse::y = 0;
int Mouse::lastX = 0;
int Mouse::lastY = 0;

float Mouse::velX   = 0;
float Mouse::velY   = 0;

bool Mouse::mouse_left      = false;
bool Mouse::mouse_middle    = false;
bool Mouse::mouse_right     = false;

int Mouse::overIndex        = -1;
int Mouse::lastOverIndex    = -1;
