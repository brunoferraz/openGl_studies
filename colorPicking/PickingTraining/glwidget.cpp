#include "glwidget.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    setAutoBufferSwap(false);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::gray);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, this->width(),this->height());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);

    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    glPointSize(15);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    drawScene();
    swapBuffers();
}

void GLWidget::drawScene(int mode)
{
    //glMatrixMode(GL_MODELVIEW);
    if(mode == 1){
        glDisable(GL_LIGHTING);
    }else{
        glEnable(GL_LIGHTING);
    }

        glLoadName(7);
//        glPushName(1);

        glColor3f(1, 0, 0);
        drawBlock(0, 0, 0);

        glColor3f(1, 1, 0);
        glLoadName(14);
//        glPushName(2);

        drawBlock(0.5, 0, 0);

}

void GLWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    //hitPicking(ev);
    colorPicking(ev);
}

void GLWidget::hitPicking(QMouseEvent *ev)
{
    qDebug() << "fdsfds";
    GLuint selectBuffer[64] = {0};
    glSelectBuffer(64, selectBuffer);

    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(0);

    GLint vp[4];
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glGetIntegerv(GL_VIEWPORT, vp);
    gluPickMatrix(ev->pos().x(), vp[3]- ev->pos().y(), 5, 5, vp);
    gluOrtho2D(-1,1,-1,1);

    paintGL();


    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    int hits = glRenderMode(GL_RENDER);
    std::cout <<  hits << std::endl;
    std::cout <<  selectBuffer[3] << std::endl;
}

void GLWidget::colorPicking(QMouseEvent *ev)
{
    glDisable(GL_DITHER);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    drawScene(1);
//    swapBuffers();
    glEnable(GL_DITHER);

    GLint viewport[4];
        GLubyte pixel[3];

        glGetIntegerv(GL_VIEWPORT,viewport);

        glReadPixels(ev->x(),viewport[3]-ev->y(),1,1,
            GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);

        qDebug() <<pixel[0] << " " << pixel[1] << " " << pixel[2];
}


void GLWidget::drawBlock(float x, float y, float z)
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x ,y, z);
    glBegin(GL_TRIANGLES);

        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(0, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);

    glEnd();

    glPopMatrix();
}
