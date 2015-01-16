#include "tool.h"
#include <QDebug>

Tool::Tool()
{

}
void Tool::mouseMove()
{

}

void Tool::mouseOver()
{

}

void Tool::mouseOut()
{

}

void Tool::mousePress()
{

}

void Tool::mouseRelease()
{

}

void Tool::display()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(target->transform.data());
    glDisable(GL_LIGHTING);
    axis->display();
    glEnable(GL_LIGHTING);
    glPopMatrix();
}
SelectTool::SelectTool()
{
    type = Tool::SELECT_TOOL;
}
CameraTool::CameraTool()
{
    type = Tool::CAMERA_TOOL;
}
DrawTool::DrawTool()
{
    type = Tool::DRAW_TOOL;
}
TranslateTool::TranslateTool()
{
    type = Tool::TRANSLATE_TOOL;
}
Axis3d *Tool::axis = new Axis3d();
AbstractObj *Tool::target;
