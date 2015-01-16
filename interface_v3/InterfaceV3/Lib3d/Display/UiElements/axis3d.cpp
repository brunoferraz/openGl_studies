#include "axis3d.h"
#include <interface.h>
Axis3d::Axis3d(QObject *parent) :
    AbstractObj(parent)
{
    xAxis.colorSelected << 1, 0, 0, 1;
    xAxis.setAngle(0, 1, 0, 0);
    xAxis.colorIdle = xAxis.colorSelected/3;
    xAxis.id = 1;
    xAxis.selected = false;

    yAxis.colorSelected << 0, 1, 0, 1;
    yAxis.setAngle(90, 0, 0, 1);
    yAxis.colorIdle = yAxis.colorSelected/3;
    yAxis.id = 2;
    yAxis.selected = false;

    zAxis.colorSelected << 0, 0, 1, 1;
    zAxis.setAngle(-90, 0, 1, 0);
    zAxis.colorIdle = zAxis.colorSelected/3;
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


void Axis::setAngle(int ang, float x, float y, float z)
{
    angle = ang;
    angleVec << x , y , z;
}

void Axis::display()
{
    glLineWidth(3);
    if(Interface::getRenderMode()==Interface::RENDER){
        color = colorIdle;
    }else{
        color = TypeCast::indexToColor(id);
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
}

void Axis::mouseOver()
{
    qDebug() << "fsdfsdf";
}

void Axis::mousePress()
{
    qDebug() << "eixo MousePres";
}
