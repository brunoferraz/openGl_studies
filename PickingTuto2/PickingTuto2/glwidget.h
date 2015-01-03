#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <QDebug>
#include <QMouseEvent>

class GLwidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLwidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
     void drawBlock(float x, float y, float z);

     void mousePressEvent(QMouseEvent *ev);
     void list_hits(GLint hits, GLuint *names);
     void gl_draw();

signals:

public slots:

};

#endif // GLWIDGET_H
