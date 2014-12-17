#ifndef GRID_H
#define GRID_H

#include <Display/Object3d/object3d.h>
#include <QList>
#include <QGLWidget>

class Grid : public Object3d
{
public:
    Grid();
    QList<Vector3f> list;
    void display();
};

#endif // GRID_H
