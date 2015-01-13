#include "axis.h"
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

Axis::Axis()
{
    xColorIdle [0] = 0.4;
    xColorIdle [1] = 0;
    xColorIdle [2] = 0;

    xColorSelected[0] = 1;
    xColorSelected[1] = 0;
    xColorSelected[2] = 0;

    yColorIdle [0] = 0;
    yColorIdle [1] = 0.4;
    yColorIdle [2] = 0;

    yColorSelected[0] = 0;
    yColorSelected[1] = 1;
    yColorSelected[2] = 0;

    zColorIdle [0] = 0;
    zColorIdle [1] = 0;
    zColorIdle [2] = 0.4;

    zColorSelected[0] = 0;
    zColorSelected[1] = 0;
    zColorSelected[2] = 1;
}

void Axis::display()
{
    GLfloat c[3] = {0, 0, 0};
    glLineWidth(3);

    glBegin(GL_LINES);
        glColor3fv(xColorIdle);
        glVertex3fv(c);
        glVertex3f(1, 0, 0);

        glColor3fv(yColorIdle);
        glVertex3fv(c);
        glVertex3f(0, 1, 0);

        glColor3fv(zColorIdle);
        glVertex3fv(c);
        glVertex3f(0, 0, 1);
    glEnd();

    glPushMatrix();
    glColor3fv(xColorIdle);
    glTranslatef(1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glutSolidCone(0.05, 0.2, 8, 2);
    glPopMatrix();

    glPushMatrix();
    glColor3fv(yColorIdle);
    glTranslatef(0, 1, 0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.05, 0.2, 8, 2);
    glPopMatrix();

    glPushMatrix();
    glColor3fv(zColorIdle);
    glTranslatef(0, 0, 1);
    glRotatef(90, 0, 0, 1);
    glutSolidCone(0.05, 0.2, 8, 2);
    glPopMatrix();
}
