#include "glcanvas.h"
#include <interface.h>
#include <Display/Primitives/tetrahedron.h>
#include <Display/UiElements/grid.h>
#include <Util/typecast.h>
GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
    viewPort = new ViewPort();
//    viewPort = new ViewPortOrto();
    Grid *g = new Grid();
    Tetrahedron *o = new Tetrahedron();

    Interface::addUiChild(*g);
    Interface::addChild(*o);

    Interface::canvas = this;
}

void GLcanvas::initializeGL()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LINE_SMOOTH);



    qglClearColor(Qt::black);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );

    viewPort->config(this->width(), this->height());
}

void GLcanvas::paintGL()
{
    glPointSize(15);
    glColor3f(1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glBegin(GL_POINTS);
//        glVertex3f(0, 0, 0);
//    glEnd();
    Interface::display();
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
    //paintGL();
    Interface::display(Interface::SELECT);
    glEnable(GL_DITHER);
    GLint viewport[4];
    GLubyte pixel[3];

    glGetIntegerv(GL_VIEWPORT,viewport);

    glReadPixels(ev->x(),viewport[3]-ev->y(),1,1,
    GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);

    //qDebug() <<pixel[0] << " " << pixel[1] << " " << pixel[2];

    int next = TypeCast::colotToIndex(pixel[0], pixel[1], pixel[2]) -1;

    if(next == -1 || next > Interface::displayList.length()){
        if(Interface::hasSelected()){
            Interface::selected()->deselect();
        }
        Interface::selectedIndex = next;
    }else{
        Interface::selectedIndex = next;
        Interface::selected()->select();
    }
}
