#include "cameraset.h"

CameraSet::CameraSet()
{
    CameraSet::camList.push_back(CameraSet::currentCamera);

    CameraOrtho* CamFront = new CameraOrtho();
    CamFront->configCam();
    //currentCamera = CamFront;

    camList.push_back(CamFront);
}

void CameraSet::init()
{
    currentCamera->init();
}

void CameraSet::configScreen(int w, int h)
{
    currentCamera->configScreen(w, h);
}

void CameraSet::mouseMove(QMouseEvent *)
{
    if(Mouse::MIDDLE){
        CameraSet::currentCamera->track(Mouse::velX);
        CameraSet::currentCamera->pedestal(Mouse::velY);
    }else if(Mouse::LEFT) {
        CameraSet::currentCamera->pan(Mouse::velX);
        CameraSet::currentCamera->tilt(Mouse::velY);
    }else if(Mouse::RIGHT) {

    }
}

void CameraSet::mouseWheel(QWheelEvent *ev)
{
    CameraSet::currentCamera->dolly(ev->angleDelta().y());
}
Camera* CameraSet::currentCamera = new Camera();
QList<Camera *> CameraSet::camList;
