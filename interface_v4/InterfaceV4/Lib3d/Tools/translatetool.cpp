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

    if(Mouse::mouse_left){
        SelectTool::mousePress();
    }else if(Mouse::mouse_middle){
        dragAndDrop = true;
    }
}

void TranslateTool::mouseRelease()
{
    dragAndDrop = false;
    axis.xAxis.deselectObj();
    axis.yAxis.deselectObj();
    axis.zAxis.deselectObj();
}

void TranslateTool::mouseMove()
{
    if(dragAndDrop){
        Eigen::Vector3f oldPos;
        oldPos << Interface::tool.getTarget()->getX(),
                Interface::tool.getTarget()->getY(),
                Interface::tool.getTarget()->getZ();
        Eigen::Vector3f nPos;
        nPos = Interface::view.getTranslateFromScreen(Mouse::velX, Mouse::velY);
        nPos = nPos/100 + oldPos;
        if(axis.xAxis.selected){
            Interface::tool.getTarget()->setPos(nPos(0), oldPos(1), oldPos(2));
        }
        if(axis.yAxis.selected){
            Interface::tool.getTarget()->setPos(oldPos(0), nPos(1), oldPos(2));
        }
        if(axis.zAxis.selected){
            Interface::tool.getTarget()->setPos(oldPos(0), oldPos(1), nPos(2));
        }
    }
}

