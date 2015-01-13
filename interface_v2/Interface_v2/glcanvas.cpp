#include "glcanvas.h"
#include <interface.h>
#include <Display/Primitives/tetrahedron.h>
#include <Display/UiElements/grid.h>
#include <Util/typecast.h>

GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
    pickingmode = false;
    angleX      = 0;
    viewPort    = new ViewPort();
//    viewPort  = new ViewPortOrto();
    Grid *g     = new Grid();
    Tetrahedron *o = new Tetrahedron();
    o->color << 0, 1, 0, 1;
    o->difuse << 0.7, 0.7, 0.7, 1;
    o->difuse /2;
    o->shininess = 10;
    o->setPos(0.3, 0, 0.3);

    Tetrahedron *o2 = new Tetrahedron();
    o2->color << 1, 1, 0, 1;
    o2->difuse << 0.7, 0.7, 0.7, 1;
    o2->difuse /2;
    o2->shininess = 10;
    o2->setPos(-1,0, -1);

    Interface::addUiChild(*g);
    Interface::addChild(*o);
    Interface::addChild(*o2);
    Interface::canvas = this;

    //setMouseTracking(true);
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

    //glEnable(GL_NORMALIZE);
    //QGLFormat::setOption(QGL::DepthBuffer);

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

    viewPort->config(this->width(), this->height());
}

void GLcanvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(pickingmode){
        Interface::display(Interface::SELECT);
    }else{
        Interface::display(Interface::RENDER);
    }
    swapBuffers();
}

void GLcanvas::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
    colorPicking(ev);
}

void GLcanvas::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
}

void GLcanvas::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::mouseMove(ev);
}

void GLcanvas::colorPicking(QMouseEvent *ev)
{
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    pickingmode = true;
    paintGL();
    glEnable(GL_DITHER);
    GLint viewport[4];
    GLubyte pixel[3];

    glGetIntegerv(GL_VIEWPORT,viewport);

    glReadPixels(ev->x(),viewport[3]-ev->y(),1,1,
    GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);

//    qDebug() <<pixel[0] << " " << pixel[1] << " " << pixel[2];

    int next = TypeCast::colorToIndex(pixel[0], pixel[1], pixel[2]);
    Interface::selectObject(next);
    pickingmode = false;
    glEnable(GL_DITHER);
    glEnable(GL_LIGHTING);
    paintGL();
}
