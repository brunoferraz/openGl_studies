#include "translatetool.h"
#include <interface.h>
#include <Io/mouse.h>
TranslateTool::TranslateTool()
{
    dragAndDrop = false;
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

void TranslateTool::mousePress()
{
    dragAndDrop = true;
    SelectTool::mousePress();
}

void TranslateTool::mouseRelease()
{
    dragAndDrop = false;
}

