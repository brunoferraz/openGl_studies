#ifndef INTERFACE_H
#define INTERFACE_H

#include <Io/mouse.h>
#include <Tools/tool.h>
#include <Display/abstractobj.h>
#include <QList>

#include <glcanvas.h>


class Interface
{
public:
    Interface();

    static int const RENDER = 0;
    static int const SELECT = 1;

    static int _targetIndex;
    static void setTargetIndex(int i);
    static int getTargetIndex();
    static bool hasSelected();
    static AbstractObj *target;

    static int _renderMode;
    static void setRenderMode(int r);
    static int getRenderMode();

    static int _toolIndex;
    static void addTool(Tool &t);
    static void setTool(int i);
    static Tool* getTool();
    static QList<Tool *> _toolList;

    static GLcanvas *canvas;
    static QList<AbstractObj *>* currentDisplayList;
    static QList<AbstractObj *>* currentSelectList;
    static QList<AbstractObj *> displayList;
    static QList<AbstractObj *> displayUiList;
    static void addChild(AbstractObj &o);

    static void display();

    static void start();
    static void stop();

    static void mousePress();
    static void mouseRelease();
    static void mouseMove();
    static void mouseOver();
    static void mouseOut();
};

#endif // INTERFACE_H
