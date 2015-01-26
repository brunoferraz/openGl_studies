#ifndef CAMERATOOL_H
#define CAMERATOOL_H

#include <Tools/tool.h>

class CameraTool : public Tool
{
public:
    CameraTool();
    void mouseMove();
    void mousePress();
};

#endif // CAMERATOOL_H
