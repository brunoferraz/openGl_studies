#include "selectTool.h"
#include <Io/mouse.h>
#include <interface.h>
SelectTool::SelectTool()
{
    type = Tool::SELECT;
}

void SelectTool::mousePress()
{
    if(Mouse::overIndex != -1){
    //When click on an object
        if(Interface::tool.hasTarget()){
            //if any object is selected, deselect and select the new one
            Interface::tool.deselect();
        }
        if(!Interface::tool.hasTarget()){
        //if none is selected, select the clicked object;
            if(Mouse::overIndex < Interface::currentSelectList->length()){
                Interface::tool.setTarget(*Interface::currentSelectList->at(Mouse::overIndex));
            }
        }
    }else{
        //When click out of an object
        if(Interface::tool.hasTarget()){
            //if any object is selected, deselect
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
