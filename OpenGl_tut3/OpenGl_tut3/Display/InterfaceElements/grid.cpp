#include "grid.h"

Grid::Grid()
{
    float step= 0.05;
    for(float i = -1; i < 1; i+= step){
        Vector3f v;
        v << i, 0, -1;
        list.push_back(v);
        v << i, 0, 1;
        list.push_back(v);
    }
    for(float i = -1; i < 1; i+= step){
        Vector3f v;
        v << -1, 0, i;
        list.push_back(v);
        v << 1, 0, i;
        list.push_back(v);
    }
}

void Grid::display()
{
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.08, 0.08, 0.08);
        for(int i =0 ; i < list.length(); i++){
           glVertex3f(list.at(i)(0),list.at(i)(1),list.at(i)(2));
        }
    glEnd();
}
