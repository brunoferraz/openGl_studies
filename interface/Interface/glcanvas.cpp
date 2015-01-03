#include "glcanvas.h"

GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLcanvas::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::gray);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, this->width(),this->height());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = float(this->width())/float(this->height());
    gluOrtho2D(-ratio,ratio,-1,1);

    glMatrixMode(GL_MODELVIEW);
}

void GLcanvas::paintGL()
{
   glPointSize(15);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glBegin(GL_POINTS);
        glVertex3f(-1, 1, 0);
   glEnd();
}
