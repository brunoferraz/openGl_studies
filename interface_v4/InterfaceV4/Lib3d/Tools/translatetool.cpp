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
        if(axis.xAxis.selected){
            Eigen::Vector3f nPos;
            nPos = Interface::view.getTranslateFromScreen(Mouse::velX, Mouse::velY);
//            nPos << Interface::tool.getTarget()->getX() + Mouse::velX/100,
//                    Interface::tool.getTarget()->getY(),
//                    Interface::tool.getTarget()->getZ();
            Interface::tool.getTarget()->setPos(nPos(0), nPos(1), nPos(2));
        }
        if(axis.yAxis.selected){
            Eigen::Vector3f nPos;
//            nPos << Interface::tool.getTarget()->getX(),
//                    Interface::tool.getTarget()->getY()- Mouse::velY/100,
//                    Interface::tool.getTarget()->getZ();
//            Interface::tool.getTarget()->setPos(nPos(0), nPos(1), nPos(2));
        }
        if(axis.zAxis.selected){
            Eigen::Vector3f nPos;
//            nPos << Interface::tool.getTarget()->getX(),
//                    Interface::tool.getTarget()->getY(),
//                    Interface::tool.getTarget()->getZ()+ Mouse::velY/100;
//            Interface::tool.getTarget()->setPos(nPos(0), nPos(1), nPos(2));
        }
    }
}

