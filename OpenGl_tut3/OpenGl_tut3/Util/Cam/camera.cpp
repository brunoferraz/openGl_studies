#include "camera.h"
#include <Util/Cam/cameraset.h>

Camera::Camera()
{
    Camera::configCam();
    info.name = "PERSPECTIVE";
    //type = CameraSet::PERSPECTIVE;
}

void Camera::setPos(float _x, float _y, float _z)
{
    info.pos(0) = _x;
    info.pos(1) = _y;
    info.pos(2) = _z;
}

void Camera::setTarget(float _x, float _y, float _z)
{
    info.target(0) = _x;
    info.target(1) = _y;
    info.target(2) = _z;

}

void Camera::setUp(float _x, float _y, float _z)
{
    info.up(0) = _x;
    info.up(1) = _y;
    info.up(2) = _z;

}

void Camera::calculateDistance()
{
    Vector3f delta;
    delta = info.target-info.pos;
    info.distance = delta.norm();

}

void Camera::track(float x)
{
    info.pos(0)       +=x/100;
    info.target(0)    +=x/100;
}

void Camera::pedestal(float y)
{
    info.pos(1)       +=y/100;
    info.target(1)    +=y/100;
}

void Camera::dolly(float z)
{
    info.pos(2)       +=z/300;
}

void Camera::pan(float d)
{
    float panRad = d * 3.14/180;
    panRad /= 5;
    Matrix3f rotMat;
    rotMat << std::cos(panRad), 0, std::sin(panRad), 0, 1, 0, -std::sin(panRad), 0, std::cos(panRad);
    Vector3f lastpos = info.pos;
    info.pos = rotMat * info.pos;

    float deltaX = info.pos(0) - lastpos(0);
    info.pos(0)      -= deltaX;
    info.target(0)   -= deltaX;
    info.pos(2)      = lastpos(2); // Fix Z position

}

void Camera::tilt(float d)
{
    float tiltRad = d * 3.14/180;
    tiltRad /= -5;
    Matrix3f rotMat;
    rotMat << 1, 0, 0, 0, std::cos(tiltRad), -std::sin(tiltRad), 0, std::sin(tiltRad), std::cos(tiltRad);
    Vector3f lastpos = info.pos;
    info.pos = rotMat * info.pos;
    info.up  = rotMat * info.up;

    float deltaY = info.pos(1) - lastpos(1);
    info.pos(1)      -= deltaY;
    info.target(1)   -= deltaY;
    info.pos(2)      = lastpos(2); // Fix Z position

}

void Camera::rotateY(float d)
{
    float rot = d * 3.14/180;
    rot /= -2;
    Matrix3f rotMat;
    rotMat << std::cos(rot), 0, std::sin(rot), 0, 1, 0, -std::sin(rot), 0, std::cos(rot);
    Vector3f lastpos = info.pos;
    info.pos = rotMat * info.pos;
}

void Camera::rotateZ(float d)
{
    float rot = d * 3.14/180;
    rot /= 2;
    Matrix3f rotMat;
    rotMat << 1, 0, 0, 0, std::cos(rot), -std::sin(rot), 0, std::sin(rot), std::cos(rot);
    Vector3f lastpos = info.pos;
    info.pos = rotMat * info.pos;
}

void Camera::resetCamera()
{
    info = defaultInfo;
}

void Camera::configScreen(int w, int h)
{
    if(h!=1 && w!=1){
        info.viewPort_height = h;
        info.viewPort_width  = w;
    }
    glViewport(0, 0, info.viewPort_width, info.viewPort_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio     = info.viewPort_width/info.viewPort_height;
    gluPerspective(info.fov, ratio, info.near, info.far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(info.pos(0),    info.pos(1),      info.pos(2),
              info.target(0), info.target(1),   info.target(2),
              info.up(0),     info.up(1),       info.up(2));


}

void Camera::init()
{
//    Vector3f angleBase;
//    angleBase << 0.0, 0.0, -1.0;
//    Vector3f posBase;
//    posBase = pos;
//    posBase(2) = 0;
//    posBase.normalize();
//    panAngle = std::acos(angleBase.dot(posBase))*180/3.14;

//    posBase = pos;
//    posBase(0) = 0;
//    posBase.normalize();
//    tiltAngle = std::acos(angleBase.dot(posBase))*180/3.14;
//    Camera::calculateDistance();
}

void Camera::configCam(int cam)
{
    info.pos         = Vector3f(0.0, 2, -2.0);
    info.target      = Vector3f(0.0, 0.0, 0.0);
    info.up          = Vector3f(0.0, 1.0, 0.0);
    info.tiltAngle   = 0;
    info.panAngle    = 0;
    info.fov         = 45;
    info.near        = 0.1;
    info.far         = 100;

    defaultInfo = info;
}

void Camera::mouseMove()
{
    if(Mouse::MIDDLE){
        CameraSet::currentCamera->track(Mouse::velX);
        CameraSet::currentCamera->pedestal(Mouse::velY);
    }else if(Mouse::LEFT) {
        CameraSet::currentCamera->rotateY(Mouse::velX);
        CameraSet::currentCamera->rotateZ(Mouse::velY);
    }else if(Mouse::RIGHT) {
        CameraSet::currentCamera->pan(Mouse::velX);
        CameraSet::currentCamera->tilt(Mouse::velY);
    }
}
