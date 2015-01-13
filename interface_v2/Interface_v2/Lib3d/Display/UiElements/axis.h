#ifndef AXIS_H
#define AXIS_H

#include <Display/abstractobj.h>
#include <GL/gl.h>


class Axis : public AbstractObj
{
public:
    Axis();
    GLfloat xColorIdle[3];
    GLfloat xColorSelected[3];

    GLfloat yColorIdle[3];
    GLfloat yColorSelected[3];

    GLfloat zColorIdle[3];
    GLfloat zColorSelected[3];

    void display();
};

#endif // AXIS_H
