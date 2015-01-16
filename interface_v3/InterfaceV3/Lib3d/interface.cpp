#include "interface.h"
#include <QDebug>
#include <Tools/tool.h>

Interface::Interface()
{

}

void Interface::setTargetIndex(int i)
{
    if(hasSelected()){
        target->deselectObj();
    }
    _targetIndex = i;
    if(getTargetIndex()!=-1 && getTargetIndex() < currentSelectList->length()){
        target = currentSelectList->at(_targetIndex);
        if(Interface::getTool()->type == Tool::SELECT_TOOL){
            Interface::getTool()->target = target;
        }
    }
}

int Interface::getTargetIndex()
{
    return _targetIndex;
}

bool Interface::hasSelected()
{
    if(getTargetIndex()==-1){
        return false;
    }else{
        return true;
    }
}
void Interface::setRenderMode(int r)
{
    _renderMode = r;
}

int Interface::getRenderMode()
{
    return _renderMode;
}

void Interface::addTool(Tool &t)
{
    _toolList.push_back(&t);
}

void Interface::setTool(int i)
{
    _toolIndex = i;
    if(Interface::hasSelected()){
      Interface::getTool()->target = Interface::target;
    }
}

Tool* Interface::getTool()
{
    return Interface::_toolList.at(Interface::_toolIndex);
}

void Interface::addChild(AbstractObj &o)
{
    displayList.push_back(&o);
    o.id = displayList.length();
}

void Interface::display()
{
    for(int i = 0; i < currentDisplayList->length(); i++){
        currentDisplayList->at(i)->display();
    }
    if(Interface::getTool()->type == Tool::SELECT_TOOL){
        if(Interface::hasSelected()){
            Interface::getTool()->display();
        }
    }
}

void Interface::start()
{
   canvas->setMouseTracking(true);
   currentDisplayList   =   &displayList;
   currentSelectList    =   &displayList;
   Interface::addTool(*(new SelectTool()));
   Interface::addTool(*(new CameraTool()));
   Interface::addTool(*(new DrawTool()));
   Interface::addTool(*(new TranslateTool()));
   Interface::setTool(Tool::SELECT_TOOL);
}

void Interface::mousePress()
{
    setTargetIndex(Mouse::overIndex);
    if(hasSelected()){
        target->mousePress();
        target->selectObj();
    }
}

void Interface::mouseRelease()
{
    currentDisplayList->at(Mouse::overIndex)->mouseRelease();
}

void Interface::mouseMove()
{

}

void Interface::mouseOver()
{
    currentDisplayList->at(Mouse::overIndex)->mouseOver();
}

void Interface::mouseOut()
{
    currentDisplayList->at(Mouse::lastOverIndex)->mouseOut();
}

int Interface::_renderMode  = Interface::RENDER;
int Interface::_targetIndex = -1;
int Interface::_toolIndex   =  0;


GLcanvas *Interface::canvas;
QList<AbstractObj *>*   Interface::currentDisplayList;
QList<AbstractObj *>*   Interface::currentSelectList;
QList<AbstractObj *>    Interface::displayList;
QList<AbstractObj *>    Interface::displayUiList;
AbstractObj             *Interface::target;
QList<Tool *>           Interface::_toolList;
