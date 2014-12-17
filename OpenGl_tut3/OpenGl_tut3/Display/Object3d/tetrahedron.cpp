#include "tetrahedron.h"

Tetrahedron::Tetrahedron()
{
    Point_3 p( 1.0, 0.0, 0.0);
    Point_3 q( 0.0, 1.0, 0.0);
    Point_3 r( 0.0, 0.0, 1.0);
    Point_3 s( 0.0, 0.0, 0.0);
    P.make_tetrahedron( p, q, r, s);
}

void Tetrahedron::display()
{
//    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
//    GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

    GLfloat shininess[] = {50};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    Object3d::display();
}
