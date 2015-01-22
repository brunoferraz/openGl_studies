#ifndef TRANSLATETOOL_H
#define TRANSLATETOOL_H

#include <Tools/tool.h>
#include <Display/UiElements/axis3d.h>

class TranslateTool : public Tool
{
public:
    TranslateTool();
    Axis3d axis;

    void display();
};

#endif // TRANSLATETOOL_H
