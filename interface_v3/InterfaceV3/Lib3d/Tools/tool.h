#ifndef TOOL_H
#define TOOL_H
#include <Display/abstractobj.h>
#include <Display/UiElements/axis3d.h>
class Tool
{
public:
    Tool();
    static int const SELECT_TOOL     = 0;
    static int const CAMERA_TOOL     = 1;
    static int const DRAW_TOOL       = 2;
    static int const TRANSLATE_TOOL  = 3;

    static Axis3d *axis;
    static AbstractObj *target;
    static void setTarget(AbstractObj &o);

    int type;

    virtual void mouseMove();
    virtual void mouseOver();
    virtual void mouseOut();
    virtual void mousePress();
    virtual void mouseRelease();

    virtual void display();
};

class SelectTool :public Tool
{
public:
    SelectTool();
};

class CameraTool: public Tool
{
public:
    CameraTool();
};

class DrawTool :public Tool
{
public:
    DrawTool();
};

class TranslateTool: public Tool
{
public:
    TranslateTool();
};

#endif // TOOL_H
