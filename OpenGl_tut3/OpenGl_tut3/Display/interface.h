#ifndef INTERFACE_H
#define INTERFACE_H

#include <Display/Object3d/InterfaceElements/grid.h>
#include <Display/Object3d/object3d.h>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QList>
#include <QString>
#include <Util/Cam/cameraset.h>
#include <Util/keyboard.h>
#include <Util/mouse.h>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <glwidget.h>
#include <QList>
#include <QPushButton>

class Glwidget;

class Interface
{
public:
    Interface();
    static QLabel *viewPortLabel;

    static bool                 bCamera;
    static bool                 bShape;
    static Glwidget*            canvas;
    static QList<QPushButton>   buttonList;

    static void mouseWheelEvent     (QWheelEvent *ev);
    static void MouseMove     (QMouseEvent *ev);
    static void mousePressEvent     (QMouseEvent *ev);
    static void mouseReleaseEvent   (QMouseEvent *ev);

    static void KeyboardPressEvent  (QKeyEvent *ev);
    static void KeyboardReleaseEvent(QKeyEvent *ev);

    //Grid            *grid;
    void display();
};

#endif // INTERFACE_H
