#include "basichedron.h"

BasicHedron::BasicHedron()
{
    deselect();
}

void BasicHedron::display()
{
    glColor4f(color(0), color(1), color(2), color(3));
    std::transform( P.facets_begin(), P.facets_end(), P.planes_begin(),Plane_from_facet());
    glBegin(GL_TRIANGLES);
        CGAL::set_ascii_mode( std::cout);
        namePolyhedron();
        float vertexCounter = 0;
        for ( Facet_iterator i = P.facets_begin(); i != P.facets_end(); ++i) {
            Halfedge_facet_circulator j;
            j= i->facet_begin();

            // Facets in polyhedral surfaces are at least triangles.
            CGAL::Vector_3<Kernel> fnormal = i->plane().orthogonal_vector();
            Vector3f vn;
            vn << fnormal[0],fnormal[1],fnormal[2];
            vn.normalize();
            glNormal3f (vn(0), vn(1), vn(2));
            CGAL_assertion( CGAL::circulator_size(j) >= 3 );
            do {
                Point_3 *p = &j->vertex()->point();
                nameVertex(vertexCounter);
                glVertex3f(p->x(), p->y(), p->z());
                vertexCounter++;
            } while ( ++j != i->facet_begin());
        }
    glEnd();
    if(selected){
        boundingBox.display();
    }
}
