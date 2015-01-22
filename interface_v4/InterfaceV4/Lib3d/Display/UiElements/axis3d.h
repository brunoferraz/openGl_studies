#ifndef AXIS3D_H
#define AXIS3D_H

#include <Display/abstractobj.h>

class Axis : public AbstractObj
{
    Q_OBJECT
public:
    Eigen::Vector4f colorIdle;
    Eigen::Vector4f colorSelected;
    Eigen::Vector4f color;

    Eigen::Vector3f angleVec;
    float angle;
    void setAngle(int ang, float x, float y, float z);

    void display();
    void mouseOver();
    void mousePress();
    int id;

    bool selected;
};

class Axis3d : public AbstractObj
{
    Q_OBJECT
public:
    explicit Axis3d(QObject *parent = 0);
    Axis xAxis;
    Axis yAxis;
    Axis zAxis;

    QList<AbstractObj *> list;

    void display();
signals:

public slots:

};


#endif // AXIS3D_H
