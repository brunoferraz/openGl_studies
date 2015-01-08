#ifndef INTERFACE_H
#define INTERFACE_H

#include <QList>
#include <Lib3d/Display/abstractobj.h>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glcanvas.h>

class Interface
{
public:
    Interface();

    static int tool;
    static int typeSel;
    static int selectedIndex;
    static GLcanvas *canvas;

    static QList<AbstractObj *> displayList;
    static void addChild(AbstractObj &o);
    static void removeChild(AbstractObj &o);

    static AbstractObj* selected();
    static bool hasSelected();
    static void mousePress();
    static void mouseRelease();
    static void mouseMove();

    static void display();
    static void render();
};
class Mouse{
public:
    static int const BUTTON_LEFT    = 0;
    static int const BUTTON_RIGHT   = 1;
    static int const BUTTON_MIDDLE  = 2;

    static bool left;
    static bool right;
    static bool middle;

    static float x;
    static float y;
    static float velX;
    static float velY;
    static float lastPosX;
    static float lastPosY;
    static void setPos(float _x=0, float _y=0);

    static void mouseMove(QMouseEvent *ev);
    static void mousePress(QMouseEvent *ev);
    static void mouseRelease(QMouseEvent *ev);
    static void picking(int x, int y);
};

class Tool
{
public :
    static int const SELECT     = 0;
    static int const DRAW       = 1;
    static int const TRANSLATE  = 2;
    static int const CAMERA     = 3;
};

class TypeSel
{
public:
    static int const VERTEX     = 0;
    static int const EDGE       = 1;
    static int const FACE       = 2;
    static int const POLYHEDRON = 3;
};


#endif // INTERFACE_H
