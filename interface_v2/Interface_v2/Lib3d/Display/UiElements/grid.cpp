#include "grid.h"

Grid::Grid()
{
}

void Grid::display(int mode)
{
    float step = 0.05;
    float alt   = -0.009;
    glLineWidth(1);
    glColor4f(0.2, 0.2, 0.2, 1);
    glBegin(GL_LINES);
        for(float i = -1; i <= 1; i+=step){
            glVertex3d(i,   alt,    -1);
            glVertex3d(i,   alt,    1);
        }
        for(float i = -1; i <= 1; i+=step){
            glVertex3d(-1,   alt,   i);
            glVertex3d(1,   alt,    i);
        }
    glEnd();
    glLineWidth(3);
    step = 0.5;
    glBegin(GL_LINES);
        for(float i = -1; i <= 1; i+=step){
            glVertex3d(i,   alt,    -1);
            glVertex3d(i,   alt,    1);
        }
        for(float i = -1; i <= 1; i+=step){
            glVertex3d(-1,   alt,   i);
            glVertex3d(1,   alt,    i);
        }
    glEnd();
}
