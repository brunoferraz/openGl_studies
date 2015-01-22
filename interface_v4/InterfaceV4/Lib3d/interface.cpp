#include "interface.h"
#include <Io/keyboard.h>

Interface::Interface()
{
}

void Interface::setRenderMode(int i)
{
    if(i == Interface::SELECT){
        glDisable(GL_DITHER);
        glDisable(GL_LIGHTING);
    }else if(i == Interface::RENDER){
        glEnable(GL_DITHER);
        glEnable(GL_LIGHTING);
    }
    Interface::_renderMode = i;
}

int Interface::getRenderMode()
{
    return Interface::_renderMode;
}

void Interface::addChild(AbstractObj &o)
{
    displayList.push_back(&o);
    o.id = displayList.length();
}

void Interface::addUiChild(AbstractObj &o)
{
    displayUiList.push_back(&o);
    o.id = displayUiList.length();
}

void Interface::setCurrentDisplayList(QList<AbstractObj *> &l)
{
    currentDisplayList = &l;
}

void Interface::setCurrentSelectList(QList<AbstractObj *> &l)
{
    currentSelectList = &l;
}

void Interface::start(int w, int h)
{
    view.setSize(w, h);
    view.setViewPort(ViewManager::PERSPECTIVE);
    setCurrentDisplayList(displayList);
    setCurrentSelectList(displayList);
}

void Interface::display()
{
    if(Interface::getRenderMode() == Interface::RENDER){
        tool.display();
        for(int i = 0; i < currentDisplayList->length(); i++)
        {
            currentDisplayList->at(i)->display();
        }
    }else if(Interface::getRenderMode() == Interface::SELECT){
        for(int i = 0; i < currentSelectList->length(); i++)
        {
            currentSelectList->at(i)->display();
        }
    }
    if(displayUiList.length()>0){
        if(Interface::getRenderMode() == Interface::RENDER){
            for(int i = 0; i < displayUiList.length(); i++)
            {
                displayUiList.at(i)->display();
            }
        }
    }
}

void Interface::mouseMove()
{
    tool.mouseMove();
}

void Interface::mouseOver()
{
    tool.mouseOver();
}

void Interface::mouseOut()
{
    tool.mouseOut();
}

void Interface::mousePress()
{
    tool.mousePress();
}

void Interface::mouseRelease()
{
    tool.mouseRelease();
}

void Interface::keyPress()
{
    if(Keyboard::Key_c){
        tool.setTool(Tool::CAMERA);
    }else if(Keyboard::Key_v){
        tool.setTool(Tool::SELECT);
    }else if(Keyboard::Key_d){
        tool.setTool(Tool::DRAW);
    }else if(Keyboard::Key_t){
        tool.setTool(Tool::TRANSLATE);
    }
    canvas->update();
}

void Interface::keyRelease()
{

}

GLcanvas *Interface::canvas;
int Interface::_renderMode = Interface::RENDER;
ViewManager Interface::view;
ToolManager Interface::tool;
QList<AbstractObj *> Interface::displayList;
QList<AbstractObj *> Interface::displayUiList;
QList<AbstractObj *> *Interface::currentDisplayList;
QList<AbstractObj *> *Interface::currentSelectList;
