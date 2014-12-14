#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QList>
#include <Display/Object3d/object3d.h>

class DisplayList
{
public:
    DisplayList();

    static int numChildren;
    static QList<Object3d *> list;

    static void addChild(Object3d &o);
    static void removeChild(Object3d &o);

    static void display();
};

#endif // DISPLAYLIST_H
