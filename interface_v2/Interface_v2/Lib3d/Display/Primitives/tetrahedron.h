#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include <Display/Primitives/basichedron.h>

class Tetrahedron : public BasicHedron
{
public:
    Tetrahedron();
    void display(int mode=0);
};

#endif // TETRAHEDRON_H
