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
    static Vector3f pos;
    static Vector3f target;
    static Vector3f up;

    static float tiltAngle;
    static float panAngle;

    static float distance;

    static float fov;
    static float near;
    static float far;

    static void setPos(float _x, float _y, float _z);
    static void setTarget(float _x, float _y, float _z);
    static void setUp(float _x, float _y, float _z);

    static void track(float x);
    static void pedestal(float y);
    static void dolly(float z);
    static void pan(float angle);
    static void tilt(float angle);

    static void configScreen(int w, int h);

    static void display();

    static void init();
};

#endif // CAMERA_H
