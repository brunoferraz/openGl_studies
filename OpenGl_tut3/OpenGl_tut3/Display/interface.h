#ifndef INTERFACE_H
#define INTERFACE_H

#include <Display/Object3d/InterfaceElements/grid.h>
#include <Display/Object3d/object3d.h>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QList>
#include <QString>

class Interface
{
public:
    Interface();
    static QLabel *viewPortLabel;

    static bool bCamera;
    static bool bShape;

    //Grid            *grid;
    void display();
};

#endif // INTERFACE_H
