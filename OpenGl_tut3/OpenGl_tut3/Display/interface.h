#ifndef INTERFACE_H
#define INTERFACE_H

#include <Display/InterfaceElements/grid.h>
#include <Display/Object3d/object3d.h>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QList>

class Interface
{
public:
    Interface();
    static QLabel *viewPortLabel;

//    static inline void setviewPortLabel(QLabel* l) { Interface::viewPortLabel = l;};

    //Grid            *grid;
    void display();
};

#endif // INTERFACE_H
