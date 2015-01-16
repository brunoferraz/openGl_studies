#include "glcanvas.h"
#include <interface.h>
#include <Display/Primitives/basichedron.h>
#include <Display/Primitives/tetrahedron.h>
#include <Display/UiElements/grid.h>

GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
    Interface::canvas = this;
    Interface::start();

    Grid *grid = new Grid(this);

    Tetrahedron *a = new Tetrahedron(this);
    a->color << 0, 1, 1, 1;
    a->color = a->color/2;
    a->difuse << 0.7, 0.7, 0.7, 1;
    a->shininess = 1;
    a->setPos(-0.3, 0, -0.3);

    Tetrahedron *b = new Tetrahedron(this);
    b->color << 0, 1, 0, 1;
    b->color = b->color/2;
    b->difuse << 0.7, 0.7, 0.7, 1;
    b->shininess = 10;
    b->setPos(0.3, 0, 0.3);

    Interface::addChild(*grid);
    Interface::addChild(*a);
    Interface::addChild(*b);
}

void GLcanvas::initializeGL()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    setAutoBufferSwap(false);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_LINE_SMOOTH);

    GLfloat light_ambient[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 0.0, 0.0 };

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

    view.config(this->width(), this->height());
}

void GLcanvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(30);

    Interface::display();
    if(Interface::getRenderMode() == Interface::RENDER){
        swapBuffers();
    }
}

void GLcanvas::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
}

void GLcanvas::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::mouseMove(ev);
}

void GLcanvas::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
}
