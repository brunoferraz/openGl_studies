#ifndef BASICHEDRON_H
#define BASICHEDRON_H


#include <iostream>
#include <Eigen/Dense>
#include <QList>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <Display/abstractobj.h>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/HalfedgeDS_vector.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Plane_3.h>

#include <Display/UiElements/boundingbox.h>

#include <QString>

#include <QString>

typedef CGAL::Simple_cartesian<double>                  Kernel;
typedef Kernel::Point_3                                 Point_3;
typedef Kernel::Plane_3                                 Plane_3;
typedef CGAL::Polyhedron_3<Kernel>                      Polyhedron;
typedef Polyhedron::Facet_iterator                      Facet_iterator;
typedef Polyhedron::Facet_handle                        Facet_handle;
typedef Polyhedron::Halfedge_around_facet_circulator    Halfedge_facet_circulator;

typedef Polyhedron::Vertex_iterator                     Vertex_iterator;

struct Plane_from_facet {
    Polyhedron::Plane_3 operator()(Polyhedron::Facet& f) {
    Polyhedron::Halfedge_handle h = f.halfedge();
    return Polyhedron::Plane_3( 	h->vertex()->point(),
                                    h->next()->vertex()->point(),
                                    h->opposite()->vertex()->point());
    }
};



class BasicHedron : public AbstractObj
{
public:
    BasicHedron();
    Polyhedron P;
    BoundingBox boundingBox;

    void createBoundingBox();
    void display();
};

#endif // BASICHEDRON_H
