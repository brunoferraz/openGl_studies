#include "glwidget.h"

Glwidget::Glwidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(this->parentWidget()->width(), this->parentWidget()->height());
}

void Glwidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    //CameraSet::currentCamera->setPos(0, 0, -4);
    CameraSet::init();
    configScreen(this->width(), this->height());
}

void Glwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawScene();
}

void Glwidget::drawScene()
{
    glPointSize(10);
    glBegin(GL_POINTS);
    float factor = 10;
    QColor color(255, 255, 255);
    float step = factor/200;
        for(float j= -1; j < 1; j+=step){
            qglColor(color);
            for(int i = 0; i < 360; i+=10){
                GLfloat posX, posY, posZ;
                posX = std::sin(i);
                posY = j;
                posZ = std::cos(i);
                glVertex3f(posX, posY, posZ);
            }
            color.setRgb(color.red()-step*100, color.green()-step*50, color.blue()-step*10);
        }
    glEnd();
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
