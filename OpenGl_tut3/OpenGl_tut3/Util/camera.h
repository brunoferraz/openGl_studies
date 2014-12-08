#ifndef CAMERA_H
#define CAMERA_H

#include <ogldev_math_3d.h>
#include <QDebug>
#include <stdio.h>
#include <iostream>

using namespace std;
class Camera
{
public:
    Camera();
    static Vector3f pos;
    static Vector3f target;
    static Vector3f up;
    static Vector3f delta;
    static float distance;

    static void setPos(float _x, float _y, float _z);
    static void setTarget(float _x, float _y, float _z);
    static void setUp(float _x, float _y, float _z);

    static void track(float x);
    static void pedestal(float y);
    static void dolly(float z);
    static void pan(float angle);
    static void tilt(float angle);

    static void calculateDistance();

    static void init();
};

#endif // CAMERA_H
