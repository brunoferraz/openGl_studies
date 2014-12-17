#include "cameraortho.h"

CameraOrtho::CameraOrtho()
{
    info.name = "Ortho";
    axysDolly    = 1;
    axysTrack    = 0;
    axysPedestal = 1;
}

void CameraOrtho::configScreen(int w, int h)
{
    if(h!=1 && w!=1){
        info.viewPort_height = h;
        info.viewPort_width  = w;
    }
    glViewport(0, 0, info.viewPort_width, info.viewPort_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    Vector3f delta = info.pos - info.target;
    float factor    = delta.norm();
    float ratio     = info.viewPort_width/info.viewPort_height;
    glOrtho(ratio * factor, -ratio * factor, -factor, factor, info.near, info.far);
    gluLookAt(info.pos(0),    info.pos(1),      info.pos(2),
              info.target(0), info.target(1),   info.target(2),
              info.up(0),     info.up(1),       info.up(2));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CameraOrtho::track(float x)
{
    Vector3f n = info.pos;
    n(axysTrack) -= x/100;
    info.pos = n;
    n = info.target;
    n(axysTrack) -= x/100;
    info.target = n;
}

void CameraOrtho::pedestal(float y)
{
    Vector3f n = info.pos;
    n(axysPedestal) += y/100;
    info.pos = n;
    n = info.target;
    n(axysPedestal) += y/100;
    info.target = n;
}

void CameraOrtho::dolly(float z)
{
    Vector3f nPos = info.pos;
    nPos(axysDolly) -= z/1000;
    info.pos = nPos;
}

void CameraOrtho::mouseMove()
{
    Camera::mouseMove();
}
void CameraOrtho::configCam(int cam)
{
    float dis = 1.2;
    switch(cam){
    case CameraSet::TOP:
        info.pos         = Vector3f(0.0, dis, 0.0);
        info.target      = Vector3f(0.0, 0.0, 0.0);
        info.up          = Vector3f(0.0, 0.0, 1.0);
        axysDolly   = 1;
        axysTrack   = 0;
        axysPedestal= 2;
        info.name        = "TOP";
        break;
    case CameraSet::LEFT:
        info.pos         = Vector3f(dis, 0.0, 0.0);
        info.target      = Vector3f(0.0, 0.0, 0.0);
        info.up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 0;
        axysTrack   = 2;
        axysPedestal= 1;
        info.name        = "LEFT";
        break;
    case CameraSet::FRONT:
        info.pos         = Vector3f(0.0, 0.0, -dis);
        info.target      = Vector3f(0.0, 0.0, 0.0);
        info.up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 2;
        axysTrack   = 0;
        axysPedestal= 1;
        info.name        = "FRONT";
        break;
    case CameraSet::BOTTOM:
        info.pos         = Vector3f(0.0, -dis, 0.0);
        info.target      = Vector3f(0.0, 0.0, 0.0);
        info.up          = Vector3f(0.0, 1.0, 0.0);
        axysDolly   = 1;
        axysTrack   = 0;
        axysPedestal= 2;
        info.name        = "BOTTOM";
        break;
    }
    info.near        = -10;
    info.far         = 10;

    defaultInfo = info;
}
