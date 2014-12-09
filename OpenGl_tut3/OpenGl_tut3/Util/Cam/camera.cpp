#include "camera.h"

Camera::Camera()
{

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
    panRad /= -5;
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
    gluLookAt(Camera::pos(0),    Camera::pos(1),      Camera::pos(2),
              Camera::target(0), Camera::target(1),   Camera::target(2),
              Camera::up(0),     Camera::up(1),       Camera::up(2));
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
    //qDebug() << panAngle << " " << tiltAngle;
}
Vector3f Camera::pos    = Vector3f(0.0, 0.0, 0.0);
Vector3f Camera::target = Vector3f(0.0, 0.0, 0.0);
Vector3f Camera::up     = Vector3f(0.0, 1.0, 0.0);
float Camera::distance  = 0.0;
float Camera::tiltAngle = 0;
float Camera::panAngle  = 0;
float Camera::fov       = 45;
float Camera::near      = 0.1;
float Camera::far       = 100;
