#include "select.h"
#include <Io/mouse.h>
#include <interface.h>
SelectTool::SelectTool()
{
    type = Tool::SELECT;
}

void SelectTool::mousePress()
{
    if(Mouse::overIndex!= -1){
        if(Interface::tool.hasTarget()){
             Interface::tool.deselect();
        }
        if(Mouse::overIndex > -1 && Mouse::overIndex < Interface::currentSelectList->length()){
            Interface::tool.setTarget(*Interface::currentSelectList->at(Mouse::overIndex));
        }
    }else{
        if(Interface::tool.hasTarget()){
            Interface::tool.deselect();
        }
    }
}

void SelectTool::mouseOver()
{

}

void SelectTool::mouseOut()
{

}

void SelectTool::display()
{
    if(Interface::tool.hasTarget()){

    }
}
