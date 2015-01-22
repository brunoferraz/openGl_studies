#include "toolmanager.h"
#include <Tools/tool.h>
#include <Tools/select.h>
#include <Tools/cameratool.h>
#include <Tools/drawtool.h>
#include <Tools/translatetool.h>

#include <Io/mouse.h>

ToolManager::ToolManager()
{
    hasSelected = false;
    list.push_back(new SelectTool());
    list.push_back(new CameraTool());
    list.push_back(new DrawTool());
    list.push_back(new TranslateTool());
    setTool(Tool::SELECT);
}

void ToolManager::setTool(const int i)
{
    currentTool = list.at(i);
}

bool ToolManager::hasTarget()
{
    return hasSelected;
}

void ToolManager::setTarget(AbstractObj &o)
{
    this->target = &o;
    target->selectObj();
    hasSelected = true;
}

void ToolManager::deselect()
{
    if(hasTarget()){
        getTarget()->deselectObj();
        hasSelected = false;
    }
}

AbstractObj* ToolManager::getTarget()
{
    return target;
}

void ToolManager::mouseMove()
{
    currentTool->mouseMove();
}

void ToolManager::mouseOver()
{
    currentTool->mouseOver();
}

void ToolManager::mouseOut()
{
    currentTool->mouseOut();
}

void ToolManager::mousePress()
{
    currentTool->mousePress();
}

void ToolManager::mouseRelease()
{
    currentTool->mouseRelease();
}

void ToolManager::display()
{
    currentTool->display();
}
