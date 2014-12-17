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
#include <Util/keyboard.h>

#include <Util/Cam/camera.h>
#include <Util/Cam/cameraset.h>
#include <QWheelEvent>
#include <QKeyEvent>
#include <Display/Object3d/object3d.h>
#include <Display/Object3d/tetrahedron.h>
#include <Display/Object3d/InterfaceElements/grid.h>
#include <Display/interface.h>

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
    //void keyPressEvent(QKeyEvent *ev);
    //void keyReleaseEvent(QKeyEvent *ev);

    Vector3f cameraPos;
    Object3d *obj;
    Object3d *grid;

signals:

public slots:

};

#endif // GLWIDGET_H
