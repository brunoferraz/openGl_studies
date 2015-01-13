#include "tetrahedron.h"

Tetrahedron::Tetrahedron()
{

    Point_3 p( 0.7, 0.0, 0.0);
    Point_3 q( 0.0, 0.7, 0.0);
    Point_3 r( 0.0, 0.0, 0.7);
    Point_3 s( 0.0, 0.0, 0.0);
    P.make_tetrahedron( p, q, r, s);
    boundingBox.createBoundingBox(P);
}
void Tetrahedron::display(int mode)
{
    BasicHedron::display(mode);
}
