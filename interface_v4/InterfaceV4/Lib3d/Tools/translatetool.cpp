#include "translatetool.h"
#include <interface.h>
TranslateTool::TranslateTool()
{
}

void TranslateTool::display()
{
    if(Interface::tool.hasTarget()){
        glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(Interface::tool.target->transform.data());
        axis.display();
        glPopMatrix();
    }
}
