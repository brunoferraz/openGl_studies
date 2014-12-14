#include "displaylist.h"

DisplayList::DisplayList()
{
}

void DisplayList::addChild(Object3d &o)
{
    numChildren++;
    list.push_back(&o);
}

void DisplayList::removeChild(Object3d &o)
{
    int i = list.indexOf(&o);
    list.removeAt(i);
    numChildren--;
}

void DisplayList::display()
{
    for(int i =0; i < numChildren; i++){
        list.at(i)->display();
    }
}
int DisplayList::numChildren = 0;
QList<Object3d *> DisplayList::list;
