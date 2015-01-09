#ifndef OBJ_H
#define OBJ_H

#include <Eigen/Dense>
#include <QList>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <QDebug>

using namespace Eigen;
using namespace std;

class AbstractObj
{
public:
    AbstractObj();

    int              id;
    Matrix4f         transform;
    QList<Vector3f>  list;
    bool             selected;
    Vector4f         color;

    //Selection
    virtual void select();
    virtual void deselect();

    //Change transform Matrix
     void setWidth();
     void setHeight();
     void setLength();

     float width();
     float height();
     float length();

    virtual void setPos(float x =0, float y=0, float z=0);
    virtual void setColor(float r=1, float g=1, float b=1, float a=1);

    //Maybe quality diference
     void render(); //for export
     virtual void display(int mode=0); //for viewport

     virtual void nameVertex(int n);
     virtual void namePolyhedron();
private:
    float   _width;
    float   _height;
    float   _length;
};
#endif // OBJ_H
