#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent) :
    QGLWidget(parent)
{
    resize(this->parentWidget()->width(), this->parentWidget()->height());
}

void GlWidget::initializeGL()
{
    GLenum res = glewInit();
    if(res!= GLEW_OK){
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    }
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);

    configScreen(this->width(), this->height());


}

void GlWidget::paintGL()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     drawScene();

}

void GlWidget::drawScene()
{
//    glBegin(GL_POINTS);
//    qglColor(Qt::red);
//        glVertex3f(0.0f,0.0f,0.0f);

//    glEnd();
    Vector3f Vertices[1];
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
}

void GlWidget::configScreen(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, w/h, 0.1, 100);
    gluLookAt(0, 1, 5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
}
