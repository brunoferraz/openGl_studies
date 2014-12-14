#include "object3d.h"

Object3d::Object3d()
{
    transform <<    1,  0,  0,  0,
                    0,  1,  0,  0,
                    0,  0,  1,  0,
                    0,  0,  0,  1;
    //Point_3 p( 0.0, 0.0, 0.0); Point_3 q( 1.0, 0.0, 0.0);
   // Point_3 r( 0.0, 1.0, 0.0); Point_3 s( 0.0, 0.0, 1.0);
    //P.make_tetrahedron(p,q,r,s);
    //decorator.create_loop();
    //CGAL_assertion( decorator.is_valid());
//    HDS hds;
//    Decorator decorator(hds);
//    decorator.create_loop();
//    CGAL_assertion( decorator.is_valid());
}

void Object3d::display()
{

}
