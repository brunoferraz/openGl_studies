#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <iostream>
#include <QGLWidget>
#include <QMouseEvent>
#include <QDebug>
#include <Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <ogldev_math_3d.h>


class GlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GlWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();

    void drawScene();

    void configScreen(int w, int h);
signals:

public slots:

};

#endif // GLWIDGET_H
