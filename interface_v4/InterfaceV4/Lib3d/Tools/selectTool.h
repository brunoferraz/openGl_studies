#ifndef SELECT_H
#define SELECT_H

#include <Tools/tool.h>

class SelectTool : public Tool
{
public:
    SelectTool();

    void mousePress();
    void mouseOver();
    void mouseOut();
    void display();


};

#endif // SELECT_H
