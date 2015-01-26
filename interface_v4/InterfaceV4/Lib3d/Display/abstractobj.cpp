#include "abstractobj.h"
#include <interface.h>
AbstractObj::AbstractObj(QObject *parent) :
    QObject(parent)
{
    color << 1, 1,  1,  1;
    selected = false;
    id = 0;
    difuse      <<   1,  1,  1,  1;
    specular    <<   1,  1,  1,  1;
    transform   <<      1,  0,  0,  0,
                        0,  1,  0,  0,
                        0,  0,  1,  0,
                        0,  0,  0,  1;
    shininess = 100;
}

void AbstractObj::display()
{
    glColor4fv(color.data());
    glBegin(GL_POINTS);
    for(int i = 0; i< vertexList.length();i++){
        glVertex3fv(vertexList.at(i).data());
    }
    glEnd();

}

void AbstractObj::selectObj()
{
    selected = true;
}

void AbstractObj::deselectObj()
{
    selected = false;
}

void AbstractObj::mouseOver()
{
    emit OnMouseOver();
}

void AbstractObj::mouseOut()
{
    emit OnMouseOut();
}

void AbstractObj::mousePress()
{
    emit OnMousePress();
}

void AbstractObj::mouseRelease()
{
    emit OnMouseRelease();
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

void AbstractObj::configRender()
{
    glGetBooleanv(GL_LIGHTING, stateLighting);
}

void AbstractObj::desconfigRender()
{
    if(stateLighting[0] == 1){
        glEnable(GL_LIGHTING);
    }else{
        glDisable(GL_LIGHTING);
    }
}

void AbstractObj::configTransform()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixf(transform.data());
}

void AbstractObj::desconfigTransform()
{
    glPopMatrix();
}

void AbstractObj::namePolyhedron()
{
    glColor4fv(TypeCast::indexToColor(id).data());
}

void AbstractObj::setPos(float _x, float _y, float _z)
{
    transform(0, 3) = _x;
    transform(1, 3) = _y;
    transform(2, 3) = _z;
}

float AbstractObj::getX()
{
    return transform(0, 3);
}

float AbstractObj::getY()
{
    return transform(1, 3);
}

float AbstractObj::getZ()
{
    return transform(2, 3);
}
