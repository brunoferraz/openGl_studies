#include "glwidget.h"

Glwidget::Glwidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(this->parentWidget()->width(), this->parentWidget()->height());
    cameraPos = Vector3f(0, 2, 3);
}

void Glwidget::initializeGL()
{

    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    Camera::pos.z = -5;
    Camera::init();
    configScreen(this->width(), this->height());
}

void Glwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawScene();
}

void Glwidget::drawScene()
{
    glBegin(GL_POINTS);
    float factor = 10;
    QColor color(255, 255, 255);
    float step = factor/500;
        for(float j= -1; j < 1; j+=step){
            qglColor(color);
            for(int i = 0; i < 360; i+=5){
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
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, w/h, 0.1, 100);
    gluLookAt(Camera::pos.x,    Camera::pos.y,      Camera::pos.z,
              Camera::target.x, Camera::target.y,   Camera::target.z,
              Camera::up.x,     Camera::up.y,       Camera::up.z);
    glMatrixMode(GL_MODELVIEW);
}

void Glwidget::mouseMoveEvent(QMouseEvent *ev)
{
    Mouse::setPos(ev->x(), ev->y());
    if(Mouse::MIDDLE){
        Camera::track(Mouse::velX);
        Camera::pedestal(Mouse::velY);
    }
    configScreen(this->width(), this->height());
    QGLWidget::update();
}

void Glwidget::wheelEvent(QWheelEvent *ev)
{
    Camera::dolly(ev->angleDelta().y());
    configScreen(this->width(), this->height());
    QGLWidget::update();
}

void Glwidget::mousePressEvent(QMouseEvent *ev)
{
    switch (ev->buttons()) {
    case Mouse::BUTTON_LEFT:
        Mouse::LEFT = true;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::RIGHT = true;
        break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::MIDDLE = true;
        break;
    default:
        break;
    }
    Mouse::setPos(ev->x(), ev->y());
}

void Glwidget::mouseReleaseEvent(QMouseEvent *ev)
{
    switch (ev->button()) {
    case Mouse::BUTTON_LEFT:
        Mouse::LEFT = false;
        break;
    case Mouse::BUTTON_RIGHT:
        Mouse::RIGHT = false;
        break;
    case Mouse::BUTTON_MIDDLE:
        Mouse::MIDDLE = false;
        break;
    default:
        break;
    }
}
