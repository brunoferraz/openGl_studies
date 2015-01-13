#ifndef GRID_H
#define GRID_H
#include <Display/abstractobj.h>

class Grid: public AbstractObj
{
public:
    Grid();
    void display(int mode=0); //for viewport
};

#endif // GRID_H
