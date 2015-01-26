#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <Display/abstractobj.h>

#include <stdio.h>
#include <iostream>

#include <CGAL/bounding_box.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/HalfedgeDS_vector.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Plane_3.h>

typedef CGAL::Simple_cartesian<double>                  Kernel;
typedef Kernel::Point_3                                 Point_3;
typedef Kernel::Plane_3                                 Plane_3;
typedef CGAL::Polyhedron_3<Kernel>                      Polyhedron;
typedef Polyhedron::Facet_iterator                      Facet_iterator;
typedef Polyhedron::Facet_handle                        Facet_handle;
typedef Polyhedron::Halfedge_around_facet_circulator    Halfedge_facet_circulator;

typedef Polyhedron::Vertex_iterator                     Vertex_iterator;

using namespace std;
class BoundingBox : public AbstractObj
{
    Q_OBJECT
public:
    explicit BoundingBox(QObject *parent = 0);

    Kernel::Iso_cuboid_3 box;
    void createBoundingBox(Polyhedron& p);
    void display();

signals:

public slots:

};

#endif // BOUNDINGBOX_H
