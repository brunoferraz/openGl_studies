#ifndef CAMERA_H
#define CAMERA_H

//#include <ogldev_math_3d.h>
#include <Eigen/Dense>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;
using namespace Eigen;
class Camera
{
public:
    Camera();
    Vector3f pos;
    Vector3f target;
    Vector3f up;

    float tiltAngle;
    float panAngle;

    float fov;
    float near;
    float far;

    void setPos(float _x, float _y, float _z);
    void setTarget(float _x, float _y, float _z);
    void setUp(float _x, float _y, float _z);

    void track(float x);
    void pedestal(float y);
    void dolly(float z);
    void pan(float angle);
    void tilt(float angle);

    virtual void configScreen(int w, int h);
    virtual void configCam();

    void display();

    void init();
};

#endif // CAMERA_H
