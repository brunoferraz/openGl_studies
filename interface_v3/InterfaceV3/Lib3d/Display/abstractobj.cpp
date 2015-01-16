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
    configRender();
    configTransform();
    if(Interface::getRenderMode() == Interface::RENDER){
        glColor4fv(color.data());
    }else{
        glColor4fv(TypeCast::indexToColor(id).data());
    }
    if(displayList.length()>0){
        for(int i = 0; i < displayList.length(); i++){
            displayList.at(i)->display();
        }
    }
    glBegin(GL_POINTS);
    for(int i = 0; i< vertexList.length();i++){
        glVertex3fv(vertexList.at(i).data());
    }
    glEnd();
    glPopMatrix();
}

void AbstractObj::selectObj()
{
    selected = true;
    //Interface::currentSelectList = &Tool::axis->list;
}

void AbstractObj::deselectObj()
{
    selected = false;
    //Interface::currentSelectList = &Interface::displayList;
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
    if(Interface::getRenderMode()==Interface::RENDER){
        glEnable(GL_LIGHTING);
        glEnable(GL_DITHER);
    }else if(Interface::getRenderMode()==Interface::RENDER){
        glDisable(GL_LIGHTING);
        glDisable(GL_DITHER);
    }
}

void AbstractObj::configTransform()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixf(transform.data());
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
