#ifndef INTERFACE_H
#define INTERFACE_H
#include <View/viewmanager.h>
#include <Tools/toolmanager.h>
#include <glcanvas.h>
#include <QDebug>

class Interface
{
public:
    Interface();

    static int const RENDER = 0;
    static int const SELECT = 1;

    static GLcanvas *canvas;

    static ViewManager view;
    static ToolManager tool;

    static int _renderMode;
    static void setRenderMode(int i);
    static int getRenderMode();

    static QList<AbstractObj *> *currentDisplayList;
    static QList<AbstractObj *> *currentSelectList;
    static QList<AbstractObj *> displayList;
    static QList<AbstractObj *> displayUiList;
    static void addChild(AbstractObj &o);
    static void addUiChild(AbstractObj &o);
    static void setCurrentDisplayList(QList<AbstractObj *> &l);
    static void setCurrentSelectList(QList<AbstractObj *> &l);

    static void start(int w, int h);
    static void display();

    static void mouseMove();
    static void mouseOver();
    static void mouseOut();
    static void mousePress();
    static void mouseRelease();

    static void keyPress();
    static void keyRelease();
};

#endif // INTERFACE_H
