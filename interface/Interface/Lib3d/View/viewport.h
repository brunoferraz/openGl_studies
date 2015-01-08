#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <Eigen/Dense>
#include <QString>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace Eigen;
struct CameraInfo{
    Matrix4f    transform;
    QString     name;
    int         type;

    float       viewPort_width;
    float       viewPort_height;

    float       tiltAngle;
    float       panAngle;

    float       fov;
    float       near;
    float       far;
};
class ViewPort
{
public:
    ViewPort();
    static const int PERSPECTIVE = 0;

    static const int TOP         = 1;
    static const int LEFT        = 2;
    static const int FRONT       = 3;

    static const int BOTTOM      = 4;
    static const int RIGHT       = 5;
    static const int BACK        = 6;

    CameraInfo info;

    void config(float w=1, float h=1);
    void configProjection();
    void configModelView();
    void rotate(float angle, float x, float y, float z);
};

#endif // VIEWPORT_H
