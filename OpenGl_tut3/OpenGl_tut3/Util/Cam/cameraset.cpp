#include "cameraset.h"
#include <Display/interface.h>

CameraSet::CameraSet()
{
    CameraSet::camList.push_back(CameraSet::currentCamera);

    CameraOrtho* CamTop = new CameraOrtho();
    CamTop->configCam(CameraSet::TOP);
    CameraSet::camList.push_back(CamTop);

    CameraOrtho* CamLeft = new CameraOrtho();
    CamLeft->configCam(CameraSet::LEFT);
    camList.push_back(CamLeft);

    CameraOrtho* CamFront = new CameraOrtho();
    CamFront->configCam(CameraSet::FRONT);
    camList.push_back(CamFront);

    CameraOrtho* CamBottom = new CameraOrtho();
    CamBottom->configCam(CameraSet::BOTTOM);
    camList.push_back(CamBottom);

//    CameraOrtho* CamRight = new CameraOrtho();
//    CamRight->configCam();
//    CamRight->setPos(4.0, 0.0, 0.0);
//    CamRight->name = "Right";
//    camList.push_back(CamRight);

//    CameraOrtho* CamBack = new CameraOrtho();
//    CamBack->configCam();
//    CamBack->setPos(0.0, 0.0, 0.0);
//    CamBack->name = "Back";
//    camList.push_back(CamBack);

   // currentCamera = CamTop;
}

void CameraSet::changeCam(int cam)
{
    qDebug() << cam << "  " << camList.length();
    Camera* nextCam  = camList.at(cam);
    currentCamera = nextCam;
    currentCamera->init();
    currentCamera->configScreen();
    //Interface::viewPortLabel->setText(currentCamera->name);
}

void CameraSet::init(int w, int h)
{
    for(int i = 0; i < camList.length(); i++){
        camList.at(i)->configScreen(w, h);
    }
    currentCamera->init();
}

void CameraSet::configScreen(int w, int h)
{
    currentCamera->configScreen(w, h);
}

void CameraSet::mouseMove(QMouseEvent *)
{
//    if(Mouse::MIDDLE){
//        CameraSet::currentCamera->track(Mouse::velX);
//        CameraSet::currentCamera->pedestal(Mouse::velY);
//    }else if(Mouse::LEFT) {
//        CameraSet::currentCamera->pan(Mouse::velX);
//        CameraSet::currentCamera->tilt(Mouse::velY);
//    }else if(Mouse::RIGHT) {

//    }
    CameraSet::currentCamera->mouseMove();
}

void CameraSet::mouseWheel(QWheelEvent *ev)
{
    CameraSet::currentCamera->dolly(ev->angleDelta().y());
}

void CameraSet::keyBoardEvent()
{
    if(Keyboard::CTRL && Keyboard::L){
        changeCam(LEFT);
    }else if(Keyboard::CTRL && Keyboard::P){
        changeCam(PERSPECTIVE);
    }else if(Keyboard::CTRL && Keyboard::F){
        changeCam(FRONT);
    }else if(Keyboard::CTRL && Keyboard::T){
        changeCam(TOP);
    }
}
Camera* CameraSet::currentCamera = new Camera();
QList<Camera *> CameraSet::camList;

//const int CameraSet::PERSPECTIVE = 0;

//const int CameraSet::TOP         = 1;
//const int CameraSet::LEFT        = 2;
//const int CameraSet::FRONT       = 3;

//const int CameraSet::BOTTOM      = 4;
//const int CameraSet::RIGHT       = 5;
//const int CameraSet::BACK        = 6;
