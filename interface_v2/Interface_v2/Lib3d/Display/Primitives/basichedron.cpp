#include "basichedron.h"
#include <interface.h>
#include <Util/typecast.h>
BasicHedron::BasicHedron()
{
    deselect();
}

void BasicHedron::display(int mode)
{
    glColor4f(color(0), color(1), color(2), color(3));
    configMaterial();
    GLfloat t[16];
    TypeCast::EigenMatrixToGlMatrixF(transform, t);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(t);

    if(selected){
        if(mode == Interface::RENDER){
            //RENDER
            //display object
            displayObject(mode);
            //display gizmos
            displayGizmos(mode);
        }else if(mode == Interface::SELECT){
            //SELECT
            //display gizmo
            displayGizmos(mode);
        }
    }else{
        if(mode == Interface::RENDER){
            //RENDER
            //display object
            displayObject(mode);
        }else if(mode == Interface::SELECT){
            //SELECT
            //change color
            namePolyhedron();
            //display object
            displayObject(mode);
        }
    }
    glPopMatrix();
}

void BasicHedron::displayObject(int mode)
{
    std::transform( P.facets_begin(), P.facets_end(), P.planes_begin(),Plane_from_facet());
    glBegin(GL_TRIANGLES);
        CGAL::set_ascii_mode( std::cout);
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
                glVertex3f(p->x(), p->y(), p->z());
                vertexCounter++;
            } while ( ++j != i->facet_begin());
        }
    glEnd();
}

void BasicHedron::displayGizmos(int mode)
{
    glDisable(GL_LIGHTING);
    if(mode == Interface::RENDER){
        boundingBox.display();
    }
    axis.display(mode);
    glEnable(GL_LIGHTING);
}
