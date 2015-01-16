#include "axis.h"
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <Util/typecast.h>
#include <interface.h>

Axis3d::Axis3d()
{
    xAxis.setColor(1, 0, 0, 1);
    xAxis.setAngle(0, 1, 0, 0);
    xAxis.id = 1;
    xAxis.selected = false;
    xAxis.mouseOver = false;
    list.push_back(xAxis);

    yAxis.setColor(0, 1, 0, 1);
    yAxis.setAngle(90, 0, 0, 1);
    yAxis.id = 2;
    yAxis.selected = false;
    yAxis.mouseOver = false;
    list.push_back(yAxis);

    zAxis.setColor(0, 0, 1, 1);
    zAxis.setAngle(-90,0, 1, 0);
    zAxis.id = 3;
    zAxis.selected = false;
    zAxis.mouseOver = false;
    list.push_back(zAxis);
}

void Axis3d::display(int mode)
{
    xAxis.display(mode);
    yAxis.display(mode);
    zAxis.display(mode);
}

void Axis::setColor(float r, float g, float b, float a)
{
    float factor = 3;
    colorSelected[0] = r;
    colorSelected[1] = g;
    colorSelected[2] = b;
    colorSelected[3] = a;
    colorIdle[0] = r/ factor;
    colorIdle[1] = g/ factor;
    colorIdle[2] = b/ factor;
    colorIdle[3] = a/ factor;
}

void Axis::setAngle(int ang, float x, float y, float z)
{
    angle = ang;
    angleVec[0] = x;
    angleVec[1] = y;
    angleVec[2] = z;
}

void Axis::display(int mode)
{
    //TRANSLATE AXIS
    GLfloat c[3] = {0, 0, 0};
    glLineWidth(3);
    Vector4f color;
    if(mode == Interface::RENDER){
        color = colorIdle;
    }else if(mode == Interface::SELECT){
        color = TypeCast::indexToColor(id);
    }

    glPushMatrix();
    glRotatef(angle, angleVec[0], angleVec[1], angleVec[2]);
        glBegin(GL_LINES);
            glColor3fv(color.data());
            glVertex3fv(c);
            glVertex3f(1, 0, 0);
        glEnd();
        glPushMatrix();
        glTranslatef(1, 0, 0);
        glRotatef(90, 0, 1, 0);
            glColor3fv(color.data());
            glutSolidCone(0.05, 0.2, 8, 2);
        glPopMatrix();
    glPopMatrix();
    //ROTATE AND SCALE AXIS
}
