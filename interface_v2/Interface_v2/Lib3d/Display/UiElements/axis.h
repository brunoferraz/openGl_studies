#ifndef AXIS_H
#define AXIS_H

#include <Display/abstractobj.h>
#include <Eigen/Dense>
#include <GL/gl.h>
#include <QList>
class Axis{
public:
    Vector4f colorIdle;
    Vector4f colorSelected;
    float angle;
    float angleVec[3];
    void setColor(float r, float g, float b, float a);
    void setAngle(int ang, float x, float y, float z);
    void display(int mode=0);
    int id;

    bool selected;
    bool mouseOver;
};

class Axis3d : public AbstractObj
{
public:
    Axis3d();

    Axis xAxis;
    Axis yAxis;
    Axis zAxis;

    QList<Axis> list;

    void display(int mode=0);
};

#endif // AXIS_H
