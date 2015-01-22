#include "viewport.h"
#include <Util/typecast.h>

ViewPort::ViewPort()
{
    info.fov        = 60;
    info.near       = 0.1;
    info.far        = 100;
    info.transform <<   1,  0,  0,  0,
                        0,  1,  0,  0,
                        0,  0,  1,  -3,
                        0,  0,  0,  1;


}

void ViewPort::config(float w, float h)
{
    if(h!=1 && w!=1){
        info.viewPort_height = h;
        info.viewPort_width  = w;
    }
    glViewport(0, 0, info.viewPort_width, info.viewPort_height);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    configProjection();
    applyTransform();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    configModelView();
}

void ViewPort::configProjection()
{
    float ratio     = info.viewPort_width/info.viewPort_height;
    gluPerspective(info.fov, ratio, info.near, info.far);
}

void ViewPort::configModelView()
{

}

void ViewPort::applyTransform()
{
    GLfloat v[16];
    TypeCast::EigenMatrixToGlMatrixF(info.transform, v);
    glMultMatrixf(v);
    glRotatef(40, 1, 1, 0);
    glGetFloatv(GL_PROJECTION_MATRIX, v);
    TypeCast::GlMatrixFToEigenMatrix(v, info.transform);
}

void ViewPort::rotate(float angle, float x, float y, float z)
{
    glMatrixMode(GL_PROJECTION);
    glRotatef(angle, x, y, z);
    glMatrixMode(GL_MODELVIEW);
}
