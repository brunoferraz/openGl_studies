#include "tetrahedron.h"

Tetrahedron::Tetrahedron()
{
    Point_3 p( 1.0, 0.0, 0.0);
    Point_3 q( 0.5, 1.0, 0.5);
    Point_3 r( 0.0, 0.0, 1.0);
    Point_3 s( 0.0, 0.0, 0.0);
    P.make_tetrahedron( p, q, r, s);
    boundingBox.createBoundingBox(P);
}
void Tetrahedron::display()
{
    BasicHedron::display();
}
