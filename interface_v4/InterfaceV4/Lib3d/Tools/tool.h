#ifndef TOOL_H
#define TOOL_H
#include <QDebug>
#include <Display/abstractobj.h>

class Tool
{
public:
    Tool();
    static int const SELECT     = 0;
    static int const CAMERA     = 1;
    static int const DRAW       = 2;
    static int const TRANSLATE  = 3;

    int type;

    AbstractObj *target;

    virtual void mouseOver();
    virtual void mouseOut();
    virtual void mousePress();
    virtual void mouseRelease();
    virtual void mouseMove();

    virtual void display();
};

#endif // TOOL_H
