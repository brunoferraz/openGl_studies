#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <iostream>
#include <Eigen/Dense>
#include <QList>

//#include <CGAL/HalfedgeDS_default.h>
//#include <CGAL/HalfedgeDS_decorator.h>

//struct Traits { typedef float Point_2; };
//typedef CGAL::HalfedgeDS_default<Traits> HDS;
//typedef CGAL::HalfedgeDS_decorator<HDS> Decorator;

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>


typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Halfedge_handle Halfedge_handle;

using namespace Eigen;
class Object3d
{
public:
    Object3d();
    Matrix4f transform;
    //HDS hds;
    //Decorator decorator;
    QList<Vector3f> vertexList;
    QList<int> vertexOrder;
    virtual void display();
};

#endif // OBJECT3D_H
