#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>
#include <iostream>
#include <stdio.h>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QDebug>

using namespace std;
class GLcanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLcanvas(QWidget *parent = 0);
    void initializeGL();
    void paintGL();

signals:

public slots:

};

#endif // GLCANVAS_H
