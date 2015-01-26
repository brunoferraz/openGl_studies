#ifndef ABSTRACTOBJ_H
#define ABSTRACTOBJ_H

#include <QObject>
#include <QList>
#include <Eigen/Dense>
#include <GL/gl.h>
#include <QDebug>
#include <Util/typecast.h>

class AbstractObj : public QObject
{
    Q_OBJECT
public:
    explicit AbstractObj(QObject *parent = 0);

    int                 id;
    Eigen::Matrix4f     transform;
    Eigen::Vector4f     color;
    Eigen::Vector4f     difuse;
    Eigen::Vector4f     specular;
    float               shininess;

    QList<AbstractObj *>    displayList;
    QList<Eigen::Vector3f>  vertexList;

    GLboolean stateLighting[1];

    virtual void display();

    bool selected;
    void selectObj();
    void deselectObj();

    virtual void mouseOver();
    virtual void mouseOut();
    virtual void mousePress();
    virtual void mouseRelease();

    virtual void configMaterial();

    virtual void configRender();
    virtual void desconfigRender();

    virtual void configTransform();
    virtual void desconfigTransform();

    virtual void namePolyhedron();

    virtual void setPos(float _x, float _y, float _z);
    float getX();
    float getY();
    float getZ();

private:
    bool isMouseOver;
    bool isMouseOut;
    bool isMousePress;

signals:
    void OnMouseOver();
    void OnMouseOut();
    void OnMousePress();
    void OnMouseRelease();
public slots:

};

#endif // ABSTRACTOBJ_H
