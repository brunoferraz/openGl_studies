#include "glwidget.h"
#include <QDebug>

GLwidget::GLwidget(QWidget *parent) :
    QGLWidget(parent)
{
    resize(this->parentWidget()->width(), this->parentWidget()->height());
}
void GLwidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::gray);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);

    glViewport(0, 0, this->width(),this->height());
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    //glOrtho(-1, 1, 1, -1, -10, 10);
    gluPerspective(60.0, this->width()/this->height(), 0.0001, 1000.0);

    //glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

}
void GLwidget::paintGL()
{
    glPointSize(15);
    qglClearColor(Qt::gray);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    qglColor(Qt::red);
    //glTranslatef(0.0, 0.0, -1.0);

        glColor3f(1.0, 0.0, 0.0);
        glLoadName(7); /* Overwrite the first name in the buffer */
        drawBlock(-0.7, 0, -2);

        glColor3f(0.0, 1.0, 0.0);
        glLoadName(14); /* Overwrite the first name in the buffer */
        drawBlock(0, 0, -4);

        glColor3f(0.0, 0.0, 1.0);
        glLoadName(21); /* Overwrite the first name in the buffer */
        drawBlock(0.7, 0, -6);
}

void GLwidget::drawBlock(float x, float y, float z)
{
    glPushMatrix();
       glTranslatef(x, y, z);
       //glutSolidCube(1.0);
       glutSolidSphere(1.0, 10,10);
       glPopMatrix();
}

void GLwidget::mousePressEvent(QMouseEvent *ev)
{
    float posX = ev->x();
    float posy = ev->y();
    GLuint buff[64] = {0};
      GLint hits, view[4];

      /*
         This choose the buffer where store the values for the selection data
         */
      glSelectBuffer(64, buff);

      /*
         This retrieve info about the viewport
         */
      glGetIntegerv(GL_VIEWPORT, view);

      /*
         Switching in selecton mode
         */
      glRenderMode(GL_SELECT);

      /*
         Clearing the name's stack
         This stack contains all the info about the objects
         */
      glInitNames();

      /*
         Now fill the stack with one element (or glLoadName will generate an error)
         */
      glPushName(0);

      /*
         Now modify the vieving volume, restricting selection area around the cursor
         */
      glMatrixMode(GL_PROJECTION);
      glPushMatrix();
      glLoadIdentity();

      /*
         restrict the draw to an area around the cursor
         */
      gluPickMatrix(posX, posy, 1.0, 1.0, view);
      gluPerspective(60.0, this->width()/this->height(), 0.0001, 1000.0);

      /*
         Draw the objects onto the screen
         */
      glMatrixMode(GL_MODELVIEW);

      /*
         draw only the names in the stack, and fill the array
         */
      //glutSwapBuffers();
      swapBuffers();
      //gl_draw();
      paintGL();

      /*
         Do you remeber? We do pushMatrix in PROJECTION mode
         */
      glMatrixMode(GL_PROJECTION);
      glPopMatrix();

      /*
         get number of objects drawed in that area
         and return to render mode
         */
      hits = glRenderMode(GL_RENDER);
      qDebug() << hits;
      /*
         Print a list of the objects
         */
      list_hits(hits, buff);

      /*
         uncomment this to show the whole buffer
       * /
       gl_selall(hits, buff);
       */

      glMatrixMode(GL_MODELVIEW);
}

void GLwidget::list_hits(GLint hits, GLuint *names)
{
    int i;

      /*
         For each hit in the buffer are allocated 4 bytes:
         1. Number of hits selected (always one,
         beacuse when we draw each object
         we use glLoadName, so we replace the
         prevous name in the stack)
         2. Min Z
         3. Max Z
         4. Name of the hit (glLoadName)
         */

      printf("%d hits:\n", hits);

      for (i = 0; i < hits; i++)
        printf( "Number: %d\n"
                "Min Z: %d\n"
                "Max Z: %d\n"
                "Name on stack: %d\n",
                (GLubyte)names[i * 4],
                (GLubyte)names[i * 4 + 1],
                (GLubyte)names[i * 4 + 2],
                (GLubyte)names[i * 4 + 3]
              );

      printf("\n");
      for (i = 0; i < hits; i++)
      {
        qDebug() << "Number " << (GLubyte)names[i * 4];
        qDebug() << "Min "<< (GLubyte)names[i * 4 + 1];
        qDebug() << "Max "<< (GLubyte)names[i * 4 + 2];
        qDebug() << "Name on stack "<< (GLubyte)names[i * 4 + 3];
      }
}

void GLwidget::gl_draw()
{

}
