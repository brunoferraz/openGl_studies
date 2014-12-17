#include "camera.h"
#include <Util/Cam/cameraset.h>

Camera::Camera()
{
    Camera::configCam();
    name = "PERSPECTIVE";
    //type = CameraSet::PERSPECTIVE;
}

void Camera::setPos(float _x, float _y, float _z)
{
    pos(0) = _x;
    pos(1) = _y;
    pos(2) = _z;
}

void Camera::setTarget(float _x, float _y, float _z)
{
    target(0) = _x;
    target(1) = _y;
    target(2) = _z;

}

void Camera::setUp(float _x, float _y, float _z)
{
    up(0) = _x;
    up(1) = _y;
    up(2) = _z;

}

void Camera::calculateDistance()
{
    Vector3f delta;
    delta = target-pos;
    distance = delta.norm();

}

void Camera::track(float x)
{
    pos(0)       +=x/100;
    target(0)    +=x/100;
}

void Camera::pedestal(float y)
{
    pos(1)       +=y/100;
    target(1)    +=y/100;
}

void Camera::dolly(float z)
{
    pos(2)       +=z/300;
}

void Camera::pan(float d)
{
    float panRad = d * 3.14/180;
    panRad /= 5;
    Matrix3f rotMat;
    rotMat << std::cos(panRad), 0, std::sin(panRad), 0, 1, 0, -std::sin(panRad), 0, std::cos(panRad);
    Vector3f lastpos = pos;
    pos = rotMat * pos;

    float deltaX = pos(0) - lastpos(0);
    pos(0)      -= deltaX;
    target(0)   -= deltaX;
    pos(2)      = lastpos(2); // Fix Z position

}

void Camera::tilt(float d)
{
    float tiltRad = d * 3.14/180;
    tiltRad /= -5;
    Matrix3f rotMat;
    rotMat << 1, 0, 0, 0, std::cos(tiltRad), -std::sin(tiltRad), 0, std::sin(tiltRad), std::cos(tiltRad);
    Vector3f lastpos = pos;
    pos = rotMat * pos;
    up  = rotMat * up;

    float deltaY = pos(1) - lastpos(1);
    pos(1)      -= deltaY;
    target(1)   -= deltaY;
    pos(2)      = lastpos(2); // Fix Z position

}

void Camera::rotateY(float d)
{
    float rot = d * 3.14/180;
    rot /= -2;
    Matrix3f rotMat;
    rotMat << std::cos(rot), 0, std::sin(rot), 0, 1, 0, -std::sin(rot), 0, std::cos(rot);
    Vector3f lastpos = pos;
    pos = rotMat * pos;
}

void Camera::rotateZ(float d)
{
    float rot = d * 3.14/180;
    rot /= 2;
    Matrix3f rotMat;
    rotMat << 1, 0, 0, 0, std::cos(rot), -std::sin(rot), 0, std::sin(rot), std::cos(rot);
    Vector3f lastpos = pos;
    pos = rotMat * pos;
}

void Camera::resetCamera()
{

}

void Camera::configScreen(int w, int h)
{
    if(h!=1 && w!=1){
        viewPort_height = h;
        viewPort_width  = w;
    }
    glViewport(0, 0, viewPort_width, viewPort_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio     = viewPort_width/viewPort_height;
    gluPerspective(fov, ratio, near, far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos(0),    pos(1),      pos(2),
              target(0), target(1),   target(2),
              up(0),     up(1),       up(2));


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
    pos         = Vector3f(0.0, 2, -2.0);
    target      = Vector3f(0.0, 0.0, 0.0);
    up          = Vector3f(0.0, 1.0, 0.0);
    tiltAngle   = 0;
    panAngle    = 0;
    fov         = 45;
    near        = 0.1;
    far         = 100;
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
