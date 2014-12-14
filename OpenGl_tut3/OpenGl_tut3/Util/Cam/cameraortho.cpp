#include "cameraortho.h"

CameraOrtho::CameraOrtho()
{
}

void CameraOrtho::configScreen(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float factor    = pos(2)/2;
    float ratio     = w/h;
    glOrtho(factor, -factor, ratio*factor, -ratio*factor, near, far);
    gluLookAt(pos(0),    pos(1),      pos(2),
              target(0), target(1),   target(2),
              up(0),     up(1),       up(2));
    glMatrixMode(GL_MODELVIEW);
}
void CameraOrtho::configCam()
{
    pos         = Vector3f(0.0, 0.0, -4.0);
    target      = Vector3f(0.0, 0.0, 0.0);
    up          = Vector3f(0.0, 1.0, 0.0);
    tiltAngle   = 0;
    panAngle    = 0;
    fov         = 45;
    near        = 0.1;
    far         = 100;
}
