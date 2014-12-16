#include "cameraortho.h"

CameraOrtho::CameraOrtho()
{
    name = "Ortho";
    axysDolly    = 1;
    axysTrack    = 0;
    axysPedestal = 1;
}

void CameraOrtho::configScreen(int w, int h)
{
    if(h!=1 && w!=1){
        viewPort_height = h;
        viewPort_width  = w;
    }
    glViewport(0, 0, viewPort_width, viewPort_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    Vector3f delta = pos - target;
    float factor    = delta.norm();
    float ratio     = viewPort_width/viewPort_height;
    glOrtho(ratio * factor, -ratio * factor, -factor, factor, near, far);
    gluLookAt(pos(0),    pos(1),      pos(2),
              target(0), target(1),   target(2),
              up(0),     up(1),       up(2));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CameraOrtho::track(float x)
{
    Vector3f n = pos;
    n(axysTrack) -= x/100;
    pos = n;
    n = target;
    n(axysTrack) -= x/100;
    target = n;
}

void CameraOrtho::pedestal(float y)
{
    Vector3f n = pos;
    n(axysPedestal) += y/100;
    pos = n;
    n = target;
    n(axysPedestal) += y/100;
    target = n;
}

void CameraOrtho::dolly(float z)
{
    Vector3f nPos = pos;
    nPos(axysDolly) -= z/1000;
    pos = nPos;
}

void CameraOrtho::mouseMove()
{
    Camera::mouseMove();
}
void CameraOrtho::configCam(int cam)
{
    float dis = 2;
    switch(cam){
    case CameraSet::TOP:
        pos         = Vector3f(0.0, dis, 0.0);
        target      = Vector3f(0.0, 0.0, 0.0);
        up          = Vector3f(0.0, 0.0, 1.0);
        axysDolly   = 1;
        axysTrack   = 0;
        axysPedestal= 2;
        name        = "TOP";
        break;
    case CameraSet::LEFT:
        pos         = Vector3f(dis, 0.0, 0.0);
        target      = Vector3f(0.0, 0.0, 0.0);
        up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 0;
        axysTrack   = 2;
        axysPedestal= 1;
        name        = "LEFT";
        break;
    case CameraSet::FRONT:
        pos         = Vector3f(0.0, 0.0, -dis);
        target      = Vector3f(0.0, 0.0, 0.0);
        up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 2;
        axysTrack   = 0;
        axysPedestal= 1;
        name        = "FRONT";
        break;
    case CameraSet::BOTTOM:
        pos         = Vector3f(0.0, -dis, 0.0);
        target      = Vector3f(0.0, 0.0, 0.0);
        up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 1;
        axysTrack   = 0;
        axysPedestal= 2;
        name        = "BOTTOM";
        break;
    }
    near        = 0.1;
    far         = 100;
}
