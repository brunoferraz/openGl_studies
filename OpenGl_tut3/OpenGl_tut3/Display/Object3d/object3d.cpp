#include "object3d.h"

Object3d::Object3d()
{
    transform <<    1,  0,  0,  0,
                    0,  1,  0,  0,
                    0,  0,  1,  0,
                    0,  0,  0,  1;

    color << 1.0 , 1.0 , 1.0, 1.0;
}

void Object3d::display()
{
//    glBegin(GL_POINTS);
//    for ( Vertex_iterator v = P.vertices_begin(); v != P.vertices_end(); ++v){
//        glVertex3f(v->point().x(), v->point().y(), v->point().z());
//    }
//    glEnd();
    // Write polyhedron in Object File Format (OFF).

   glColor4f(color(0), color(1), color(2), color(3));
   std::transform( P.facets_begin(), P.facets_end(), P.planes_begin(),Plane_from_facet());
   glBegin(GL_TRIANGLES);
       CGAL::set_ascii_mode( std::cout);
       for ( Facet_iterator i = P.facets_begin(); i != P.facets_end(); ++i) {
           Halfedge_facet_circulator j;
           j= i->facet_begin();
           // Facets in polyhedral surfaces are at least triangles.
           CGAL::Vector_3<Kernel> fnormal = i->plane().orthogonal_vector();
                       //glNormal3f (fnormal[0],fnormal[1],fnormal[2]);
           //std::cout << fnormal << std::endl;
           CGAL_assertion( CGAL::circulator_size(j) >= 3 );
           QList<Vector3f> pointList;
           do {
               Point_3 *p = &j->vertex()->point();
               Vector3f pt;
               pt << p->x(), p->y(), p->z();
               pointList.push_back(pt);
           } while ( ++j != i->facet_begin());

           Vector3f va = pointList.at(1) - pointList.at(0);
           Vector3f vb = pointList.at(2) - pointList.at(1);
           Vector3f n = va.cross(vb);
           //std::cout << n.transpose() << std::endl;
           glNormal3f (n(0), n(1), n(2));
           do {
               Point_3 *p = &j->vertex()->point();

               glVertex3f(p->x(), p->y(), p->z());
           } while ( ++j != i->facet_begin());
       }
   glEnd();
}
