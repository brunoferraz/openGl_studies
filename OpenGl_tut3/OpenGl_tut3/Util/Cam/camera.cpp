#include "camera.h"

Camera::Camera()
{
    Camera::configCam();
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

void Camera::pan(float angle)
{
    float panRad = angle * 3.14/180;
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

void Camera::tilt(float angle)
{
    float tiltRad = angle * 3.14/180;
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

void Camera::configScreen(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, w/h, near, far);
    gluLookAt(pos(0),    pos(1),      pos(2),
              target(0), target(1),   target(2),
              up(0),     up(1),       up(2));
    glMatrixMode(GL_MODELVIEW);
}

void Camera::init()
{
    Vector3f angleBase;
    angleBase << 0.0, 0.0, -1.0;
    Vector3f posBase;
    posBase = pos;
    posBase(2) = 0;
    posBase.normalize();
    panAngle = std::acos(angleBase.dot(posBase))*180/3.14;

    posBase = pos;
    posBase(0) = 0;
    posBase.normalize();
    tiltAngle = std::acos(angleBase.dot(posBase))*180/3.14;
}

void Camera::configCam()
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
