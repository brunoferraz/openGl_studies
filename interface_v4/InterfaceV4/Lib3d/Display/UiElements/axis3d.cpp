#include "axis3d.h"
#include <interface.h>
Axis3d::Axis3d(QObject *parent) :
    AbstractObj(parent)
{
    xAxis.colorSelected << 1, 0, 0, 1;
    xAxis.setAngle(0, 1, 0, 0);
    xAxis.colorIdle = xAxis.colorSelected/3;
    xAxis.color = xAxis.colorIdle;
    xAxis.lastColor = xAxis.colorIdle;
    xAxis.id = 1;
    xAxis.selected = false;

    yAxis.colorSelected << 0, 1, 0, 1;
    yAxis.setAngle(90, 0, 0, 1);
    yAxis.colorIdle = yAxis.colorSelected/3;
    yAxis.color = yAxis.colorIdle;
    yAxis.lastColor = yAxis.colorIdle;
    yAxis.id = 2;
    yAxis.selected = false;

    zAxis.colorSelected << 0, 0, 1, 1;
    zAxis.setAngle(-90, 0, 1, 0);
    zAxis.colorIdle = zAxis.colorSelected/3;
    zAxis.color = zAxis.colorIdle;
    zAxis.lastColor = zAxis.colorIdle;
    zAxis.id = 3;
    zAxis.selected = false;

    list.push_back(&xAxis);
    list.push_back(&yAxis);
    list.push_back(&zAxis);
}

void Axis3d::display()
{
    xAxis.display();
    yAxis.display();
    zAxis.display();
}

void Axis3d::deselectObj()
{
    xAxis.lastColor = xAxis.colorIdle;
    yAxis.lastColor = yAxis.colorIdle;
    zAxis.lastColor = zAxis.colorIdle;
}


Axis::Axis(QObject *parent)
{
   // selected = false;
}

void Axis::setAngle(int ang, float x, float y, float z)
{
    angle = ang;
    angleVec << x , y , z;
}

void Axis::display()
{
    configRender();
    glDisable(GL_LIGHTING);
    glLineWidth(5);
    if(Interface::getRenderMode()==Interface::SELECT){
        color = TypeCast::indexToColor(id);
         glLineWidth(30);
    }else{
        color = lastColor;
    }
    glPushMatrix();
    glRotatef(angle, angleVec(0), angleVec(1), angleVec(2));
        glBegin(GL_LINES);
            glColor3fv(color.data());
            glVertex3f(0,0,0);
            glVertex3f(1, 0, 0);
        glEnd();
        glPushMatrix();
        glTranslatef(1, 0, 0);
        glRotatef(90, 0, 1, 0);
            glColor3fv(color.data());
            glutSolidCone(0.05, 0.2, 8, 2);
        glPopMatrix();
        glPopMatrix();
    desconfigRender();
}

void Axis::mouseOver()
{
    lastColor = colorSelected;

}

void Axis::mouseOut()
{
    lastColor = colorIdle;
}

void Axis::mousePress()
{
    selected = true;
    lastColor = colorSelected;
}

void Axis::mouseRelease()
{
    selected = false;
    lastColor = colorIdle;
}
