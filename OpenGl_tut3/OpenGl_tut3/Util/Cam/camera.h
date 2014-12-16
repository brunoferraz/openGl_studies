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
#include <QString>
#include <Util/mouse.h>

using namespace std;
using namespace Eigen;
class Camera
{
public:
    Camera();
    Vector3f    pos;
    Vector3f    target;
    Vector3f    up;
    float       distance;
    QString     name;
    int         type;

    float       viewPort_width;
    float       viewPort_height;

    float       tiltAngle;
    float       panAngle;

    float       fov;
    float       near;
    float       far;

    void setPos(float _x, float _y, float _z);
    void setTarget(float _x, float _y, float _z);
    void setUp(float _x, float _y, float _z);
    void calculateDistance();

    virtual void track(float x);
    virtual void pedestal(float y);
    virtual void dolly(float z);
    virtual void pan(float d);
    virtual void tilt(float d);
    virtual void rotateY(float d);
    virtual void rotateZ(float d);
    virtual void resetCamera();


    virtual void configScreen(int w = 1,int h = 1);
    virtual void configCam(int cam =0);

    virtual void mouseMove();

    void display();

    void init();
};

#endif // CAMERA_H
