#include "glcanvas.h"
#include <Lib3d/interface.h>
#include <Lib3d/Display/Primitives/tetrahedron.h>
#include <Display/UiElements/grid.h>

GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
    Grid *g = new Grid();
    Interface::addChild(*g);
    Tetrahedron *o = new Tetrahedron();
    Interface::addChild(*o);
    Tetrahedron *o2 = new Tetrahedron();
    o2->setPos(0, -1, 0);
    o2->setColor(0.0);
    Interface::addChild(*o2);
    qDebug() << o2->id;
    Interface::canvas = this;
    //setMouseTracking(true);
}


void GLcanvas::initializeGL()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LINE_SMOOTH);

    GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 10.0, 0.0, 0.0 };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,    2.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,      1.0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION,   1.0);

    qglClearColor(Qt::black);

    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );

    viewPort.config(this->width(), this->height());
}

void GLcanvas::paintGL()
{
   glPointSize(15);
   glColor3f(1,1,1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   Interface::display();
}

void GLcanvas::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
}

void GLcanvas::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
}

void GLcanvas::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::mouseMove(ev);
}
