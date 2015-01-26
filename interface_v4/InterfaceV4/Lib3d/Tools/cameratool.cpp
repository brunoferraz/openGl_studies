#include "cameratool.h"
#include <Io/mouse.h>
#include <interface.h>

CameraTool::CameraTool()
{
    type = CAMERA;
}

void CameraTool::mouseMove()
{
    if(Mouse::mouse_left){
        Interface::view.currentView->rotate(Mouse::velX, 0, 1, 0);
        Interface::view.currentView->rotate(Mouse::velY, 1, 0, 0);
    }
}

void CameraTool::mousePress()
{

}
