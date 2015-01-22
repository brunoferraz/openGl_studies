#include "glcanvas.h"
#include <Display/Primitives/tetrahedron.h>
#include <Io/mouse.h>
#include <Lib3d/interface.h>
#include <Display/UiElements/grid.h>

GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{  
    Interface::canvas = this;

    Grid *grid = new Grid(this);
    Interface::addUiChild(*grid);

    Tetrahedron *a = new Tetrahedron(this);
    a->setPos(-1, 0, 0.5);
    a->color << 1, 0, 1, 1;
    a->shininess = 20;
    Interface::addChild(*a);

    Tetrahedron *b = new Tetrahedron(this);
    b->setPos(0.5, 0, 0.5);
    b->color << 1, 0.5, 0, 1;
    b->shininess = 20;
    Interface::addChild(*b);
}
void GLcanvas::initializeGL()
{
    Interface::start(this->width(), this->height());

    setAutoBufferSwap(false);
    setMouseTracking(true);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
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
}
void GLcanvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(10);
    Interface::display();
    if(Interface::getRenderMode() == Interface::RENDER){
        swapBuffers();
    }
}

void GLcanvas::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
    update();
}

void GLcanvas::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
    update();
}

void GLcanvas::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::mouseMove(ev);
}
