#include "interface.h"
#include <QDebug>
#include <Util/typecast.h>
#include <QGLWidget>
Interface::Interface()
{

}

void Interface::addUiChild(AbstractObj &o)
{
    Interface::uiList.push_back(&o);
    o.id = Interface::uiList.length();
}

void Interface::addChild(AbstractObj &o)
{
    Interface::displayList.push_back(&o);
    o.id = Interface::displayList.length();
}

AbstractObj* Interface::selected()
{
    if(Interface::hasSelected()){
       return Interface::displayList.at(Interface::selectedIndex);
    }else{
        //returning memory addres 0 if doesnt have object selected
        return 0;
    }
}

void Interface::selectObject(int i)
{
    int next = i-1;
    if(next == -1 || next >= Interface::displayList.length()){
        //deselect object
        if(Interface::hasSelected()){
            Interface::selected()->deselect();
            Interface::selectedIndex = -1;
        }
    }else{
        if(hasSelected()){
            //deselect object
            Interface::selected()->deselect();
        }
        //select object
        Interface::selectedIndex = i-1;
        Interface::selected()->select();
    }
}

bool Interface::hasSelected()
{
    if(Interface::selectedIndex == -1){
        return false;
    }else{
        return true;
    }
}

void Interface::mousePress()
{
//    qDebug() << "pressiona";
//    qDebug() << Mouse::left;
    if(Interface::tool == Tool::SELECT){
        //Mouse::hitPicking(int(Mouse::x), int(Mouse::y));
        //Mouse::colorPicking(Mouse::x, Mouse::y);
    }
}

void Interface::mouseRelease()
{

}

void Interface::setMouseTracking(bool b)
{
    Interface::canvas->setMouseTracking(b);
}

void Interface::mouseMove()
{
    if(Mouse::left){
        Vector3f v;
        v<< Mouse::velY, Mouse::velX, 0;
        v.normalized();
        Interface::canvas->viewPort->rotate(2, v(0), v(1), v(2));
        Interface::canvas->update();
    }
}

void Interface::display(int mode)
{
    for(int i=0; i < Interface::displayList.length(); i++){
         Interface::displayList.at(i)->display(mode);
    }
    glDisable(GL_LIGHTING);
    for(int i=0; i < Interface::uiList.length(); i++){
         Interface::uiList.at(i)->display(mode);
    }
    glEnable(GL_LIGHTING);
}

int Interface::tool             = Tool::SELECT;
int Interface::typeSel          = TypeSel::POLYHEDRON;
int Interface::selectedIndex    = 0;
QList<AbstractObj *> Interface::displayList;
QList<AbstractObj *> Interface::uiList;
GLcanvas* Interface::canvas;

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
    Interface::mouseMove();
}

void Mouse::mousePress(QMouseEvent *ev)
{
   Mouse::setPos(ev->x(), ev->y());
   //qDebug() << ev->button();
   switch(ev->button()){
    case Mouse::BUTTON_LEFT:
       Mouse::left = true;
       break;
   case Mouse::BUTTON_RIGHT:
       Mouse::right = true;
      break;
   case Mouse::BUTTON_MIDDLE:
       Mouse::middle = true;
      break;
   default:
       break;
   }
   Interface::mousePress();
   //Interface::canvas->update();
}
void Mouse::mouseRelease(QMouseEvent *ev)
{
    Mouse::setPos(ev->x(), ev->y());
    switch(ev->button()){
     case Mouse::BUTTON_LEFT:
        Mouse::left = false;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::right = false;
       break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::middle = false;
       break;
    default:
        break;
    }
    Interface::mouseRelease();
    //Interface::canvas->update();
}

bool Mouse::left        = false;
bool Mouse::right       = false;
bool Mouse::middle      = false;
float Mouse::velX       = 0;
float Mouse::velY       = 0;
float Mouse::lastPosX   = 0;
float Mouse::lastPosY   = 0;
float Mouse::x          = 0;
float Mouse::y          = 0;
