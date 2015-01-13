#include "abstractobj.h"
#include <Util/typecast.h>
#include <Lib3d/interface.h>
//#include <Eigen/OpenGLSupport>

AbstractObj::AbstractObj()
{
    id = 0;
    color       <<   1,  1,  1,  1;
    difuse      <<   1,  1,  1,  1;
    specular    <<   1,  1,  1,  1;
    transform   <<      1,  0,  0,  0,
                        0,  1,  0,  0,
                        0,  0,  1,  0,
                        0,  0,  0,  1;
    shininess = 100;
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

void AbstractObj::configMaterial()
{
    GLfloat d[4];
    TypeCast::EigenToGLfloat(difuse,d);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, d);

    GLfloat s[4];
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void AbstractObj::configTransform()
{
    GLfloat t[16];
    TypeCast::EigenMatrixToGlMatrixF(transform, t);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixf(t);
}

void AbstractObj::display(int mode)
{

}

void AbstractObj::nameVertex(int n)
{

}

void AbstractObj::namePolyhedron()
{
    Vector4f v = TypeCast::indexToColor(id);
    glColor4f(v(0), v(1), v(2), v(3));
    //std::cout << v.transpose() << "  " << id  << std::endl;

}
