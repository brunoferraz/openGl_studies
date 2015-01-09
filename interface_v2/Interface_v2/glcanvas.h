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
#include <View/viewport.h>
#include <View/viewportorto.h>

class GLcanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLcanvas(QWidget *parent = 0);

    ViewPort *viewPort;

    void initializeGL();
    void paintGL();

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void colorPicking(QMouseEvent *ev);
signals:

public slots:

};

#endif // GLCANVAS_H
