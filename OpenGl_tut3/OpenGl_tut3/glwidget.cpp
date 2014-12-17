#include "glwidget.h"
#include <mainwindow.h>

Glwidget::Glwidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(this->parentWidget()->width(), this->parentWidget()->height());
    //cameraSet.canvas = this;
    //MainWindow* main= this->parent();
    //Interface::viewPortLabel = main->label;
}

void Glwidget::initializeGL()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);

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

    CameraSet::init(this->width(), this->height());
    configScreen(this->width(), this->height());
    obj = new Tetrahedron();
    grid = new Grid();
}

void Glwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawScene();
}

void Glwidget::drawScene()
{
    glPointSize(10);
    obj->display();
    grid->display();
}

void Glwidget::configScreen(int w, int h)
{
    CameraSet::currentCamera->configScreen(w, h);
}

void Glwidget::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::setPos(ev->x(), ev->y());
    CameraSet::mouseMove(ev);
    CameraSet::currentCamera->configScreen(this->width(), this->height());
    QGLWidget::update();
}

void Glwidget::wheelEvent(QWheelEvent *ev)
{
    CameraSet::mouseWheel(ev);
    CameraSet::currentCamera->configScreen(this->width(), this->height());
    QGLWidget::update();
}

void Glwidget::mousePressEvent(QMouseEvent *ev)
{
    Mouse::mousePress(ev);
}

void Glwidget::mouseReleaseEvent(QMouseEvent *ev)
{
    Mouse::mouseRelease(ev);
}
