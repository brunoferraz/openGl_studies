#include "interface.h"
#include <QDebug>
#include <Util/typecast.h>
Interface::Interface()
{

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
    if(Interface::tool == Tool::SELECT){
        Mouse::picking(int(Mouse::x), int(Mouse::y));
    }
}

void Interface::mouseRelease()
{

}

void Interface::mouseMove()
{

}

void Interface::display()
{
    for(int i=0; i < Interface::displayList.length(); i++){
         Interface::displayList.at(i)->display();
    }
}

int Interface::tool             = Tool::SELECT;
int Interface::typeSel          = TypeSel::POLYHEDRON;
int Interface::selectedIndex    = 0;
QList<AbstractObj *> Interface::displayList;
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
    Vector3f v;
    v<< Mouse::velY, Mouse::velX, 0;
    v.normalized();
    Interface::canvas->viewPort.rotate(2, v(0), v(1), v(2));
    Interface::canvas->update();
    //std::cout << v.transpose() << std::endl;
}

void Mouse::mousePress(QMouseEvent *ev)
{
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
}
void Mouse::mouseRelease(QMouseEvent *ev)
{
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
}

void Mouse::picking(int x, int y)
{
    GLuint selectBuffer[64] = {0};
    glSelectBuffer(64, selectBuffer);

    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(0);

    GLint vp[4];
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glGetIntegerv(GL_VIEWPORT, vp);
    gluPickMatrix(x, vp[3]- y, 100, 100, vp);
    //Interface::canvas->viewPort.configProjection();
    float ratio = Interface::canvas->viewPort.info.viewPort_width/Interface::canvas->viewPort.info.viewPort_height;

    gluPerspective(Interface::canvas->viewPort.info.fov,
                   ratio,
                   Interface::canvas->viewPort.info.near,
                   Interface::canvas->viewPort.info.far);

//    TypeCast::GlMatrixFToEigenMatrix(v, info.transform);
//    gluOrtho2D(-1,1,-1,1);
//    float ratio = float(Interface::canvas->width())/float(Interface::canvas->height());
//    gluPerspective(45,ratio,0.1,1000);

    //selectRender
    Interface::display();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

//    glRenderMode(GL_RENDER);
    int hits = glRenderMode(GL_RENDER); // Number of objects selected;
    int next = selectBuffer[3]-1; // Object Selected.
    if(next == -1){
        if(Interface::hasSelected()){
            Interface::selected()->deselect();
        }
        Interface::selectedIndex = next;
    }else{
        Interface::selectedIndex = next;
        Interface::selected()->select();
    }
//    std::cout << Interface::selectedIndex << std::endl;
//    std::cout << hits << std::endl;
    //normalRender
    Interface::display();
    Interface::canvas->update();
}
bool Mouse::left    = false;
bool Mouse::right   = false;
bool Mouse::middle  = false;
float Mouse::velX   = 0;
float Mouse::velY   = 0;
float Mouse::lastPosX = 0;
float Mouse::lastPosY = 0;
float Mouse::x      = 0;
float Mouse::y      = 0;
