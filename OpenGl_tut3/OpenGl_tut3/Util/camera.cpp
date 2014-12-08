#include "camera.h"

Camera::Camera()
{
}

void Camera::setPos(float _x, float _y, float _z)
{
    pos.x = _x;
    pos.y = _y;
    pos.z = _z;
}

void Camera::setTarget(float _x, float _y, float _z)
{
    target.x = _x;
    target.y = _y;
    target.z = _z;
}

void Camera::setUp(float _x, float _y, float _z)
{
    up.x = _x;
    up.y = _y;
    up.z = _z;
}

void Camera::track(float x)
{
    pos.x       +=x/100;
    target.x    +=x/100;
}

void Camera::pedestal(float y)
{
    pos.y       +=y/100;
    target.y    +=y/100;
}

void Camera::dolly(float z)
{
    pos.z       +=z/300;
    calculateDistance();
}

void Camera::pan(float angle)
{

}

void Camera::tilt(float angle)
{
    float na = angle/120;
    //Matrix4f rotMat ={float(cos(double(na))), 0, float(sin(double(na))), 0, 1, 0, float(-sin(double(na))), 0, float(cos(double(na)))};
}

void Camera::calculateDistance()
{
    delta = pos - target;
   // distance = std::sqrt(std::pow(delta.x, 2) + std::pow(delta.y, 2) + std::pow(delta.z, 2));
}

void Camera::init()
{
    calculateDistance();
}
Vector3f Camera::pos    = Vector3f(0.0, 0.0, 0.0);
Vector3f Camera::target = Vector3f(0.0, 0.0, 0.0);
Vector3f Camera::up     = Vector3f(0.0, 1.0, 0.0);
Vector3f Camera::delta  = Vector3f(0.0, 0.0, 0.0);
float Camera::distance  = 0.0;
