#include "abstractobj.h"
#include <Util/typecast.h>
#include <Lib3d/interface.h>

AbstractObj::AbstractObj()
{
    id = 0;
    color     <<    1,  1,  1,  1;
    transform <<    1,  0,  0,  0,
                    0,  1,  0,  0,
                    0,  0,  1,  0,
                    0,  0,  0,  1;
}

void AbstractObj::select()
{
    selected = true;
}

void AbstractObj::deselect()
{
    selected = false;
}

void AbstractObj::setPos(float x, float y, float z)
{
    transform(0,3) = x;
    transform(1,3) = y;
    transform(2,3) = z;
}

void AbstractObj::setColor(float r, float g, float b, float a)
{
    color << r, g, b, a;
}

void AbstractObj::display()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    GLfloat v[16];
    TypeCast::EigenMatrixToGlMatrixF(transform, v);
    glLoadMatrixf(v);
    glColor4f(color(0), color(1), color(2), color(3));
    namePolyhedron();
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < list.length(); i++){
        GLfloat v[3] = {list.at(i)(0),list.at(i)(1),list.at(i)(2)};
        nameVertex(i);
        glVertex3fv(v);
    }
    glEnd();
    glPopMatrix();
}

void AbstractObj::nameVertex(int n)
{
    if(Interface::typeSel == TypeSel::VERTEX){
        glLoadName(n);
    }
}

void AbstractObj::namePolyhedron()
{
    if(Interface::typeSel == TypeSel::POLYHEDRON){
        glLoadName(id);
    }
}
