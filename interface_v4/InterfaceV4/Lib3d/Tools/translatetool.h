#ifndef TRANSLATETOOL_H
#define TRANSLATETOOL_H

#include <Tools/tool.h>
#include <Tools/selectTool.h>

class TranslateTool : public SelectTool
{
public:
    TranslateTool();

    bool dragAndDrop;

    void display();
    void mousePress();
    void mouseRelease();
    //void mouseMove();
};

#endif // TRANSLATETOOL_H
