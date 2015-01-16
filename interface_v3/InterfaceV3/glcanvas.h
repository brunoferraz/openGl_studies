#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <Eigen/Dense>
#include <View/viewport.h>

//using namespace Eigen;
class GLcanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLcanvas(QWidget *parent = 0);

    ViewPort view;

    void initializeGL();
    void paintGL();

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:


public slots:

};

#endif // GLCANVAS_H
