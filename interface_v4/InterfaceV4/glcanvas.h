#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Eigen/Dense>
#include <QMouseEvent>
#include <QDebug>

class GLcanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLcanvas(QWidget *parent = 0);

    void initializeGL();
    void paintGL();

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // GLCANVAS_H
