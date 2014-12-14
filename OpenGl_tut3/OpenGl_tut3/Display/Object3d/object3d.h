#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <Eigen/Dense>
#include <QList>
//#include <CGAL/Simple_cartesian.h>
//#include <CGAL/Polyhedron_3.h>
//#include <CGAL/Point_3.h>
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
//#include <CGAL/Polyhedron_3.h>
//#include <CGAL/IO/Polyhedron_iostream.h>
//#include <CGAL/Width_default_traits_3.h>
//#include <CGAL/Width_3.h>

//typedef CGAL::Exact_predicates_inexact_constructions_kernel  Kernel;
//typedef Kernel::Vector_3                                     Vector;
//typedef Kernel::Point_3                                      Point;
//typedef CGAL::Polyhedron_3<Kernel>                           Polyhedron;
//typedef Polyhedron::Point_const_iterator                     Point_iterator;

//typedef CGAL::Exact_predicates_exact_constructions_kernel    EKernel;
//typedef CGAL::Polyhedron_3<EKernel>                          EPolyhedron;
//typedef EKernel::Point_3                                     EPoint;
//typedef CGAL::Width_default_traits_3<EKernel>                Width_traits;
//typedef CGAL::Width_3<Width_traits>                          Width;


using namespace Eigen;
class Object3d
{
public:
    Object3d();
    Matrix4f transform;
    //Polyhedron P;
    QList<Vector3f> vertexList;
    QList<int> vertexOrder;
    virtual void display();
};

#endif // OBJECT3D_H
