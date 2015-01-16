#include "basichedron.h"
#include <interface.h>

BasicHedron::BasicHedron(QObject *parent) :
    AbstractObj(parent)
{
}

void BasicHedron::display()
{
    glColor4fv(color.data());
    configRender();
    configMaterial();
//    GLfloat t[16];
//    TypeCast::EigenMatrixToGlMatrixF(transform, t);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(transform.data());

    if(selected){
        if(Interface::getRenderMode() == Interface::RENDER){
            //RENDER
            //display object
            displayObject();
            //display gizmos
            displayGizmos();
        }else if(Interface::getRenderMode() == Interface::SELECT){
            //SELECT
            //display gizmo
            displayGizmos();
        }
    }else{
        if(Interface::getRenderMode() == Interface::RENDER){
            //RENDER
            //display object
            displayObject();
        }else if(Interface::getRenderMode() == Interface::SELECT){
            //SELECT
            //change color
            namePolyhedron();
            //display object
            displayObject();
        }
    }
    displayGizmos();
    glPopMatrix();
}

void BasicHedron::displayObject()
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
            Eigen::Vector3f vn;
            vn << fnormal[0],fnormal[1],fnormal[2];
            vn.normalize();
            glNormal3fv (vn.data());
            CGAL_assertion( CGAL::circulator_size(j) >= 3 );
            do {
                Point_3 *p = &j->vertex()->point();
                glVertex3f(p->x(), p->y(), p->z());
                vertexCounter++;
            } while ( ++j != i->facet_begin());
        }
    glEnd();
}

void BasicHedron::displayGizmos()
{
    if(selected){
        boundingBox.display();
    }
}
