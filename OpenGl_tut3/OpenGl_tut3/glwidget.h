#ifndef GLWIDGET_H
#define GLWIDGET_H

//#include <GL/glew.h>
#include <iostream>
#include <QGLWidget>
#include <QMouseEvent>
#include <QDebug>
#include <Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
//#include <ogldev_math_3d.h>
#include <Util/mouse.h>
#include <Util/Cam/camera.h>
#include <Util/Cam/cameraset.h>
#include <QWheelEvent>


class Glwidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit Glwidget(QWidget *parent = 0);

    CameraSet cameraSet;

    void initializeGL();
    void paintGL();

    void drawScene();

    void configScreen(int w, int h);

    void mouseMoveEvent(QMouseEvent *ev);
    void wheelEvent(QWheelEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    Vector3f cameraPos;
signals:

public slots:

};

#endif // GLWIDGET_H
