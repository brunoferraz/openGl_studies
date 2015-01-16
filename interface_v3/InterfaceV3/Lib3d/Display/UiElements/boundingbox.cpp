#include "boundingbox.h"

BoundingBox::BoundingBox(QObject *parent) :
    AbstractObj(parent)
{
     color << 0.6 ,0.6 ,0.6 , 1;
}

void BoundingBox::createBoundingBox(Polyhedron &p)
{
    std::vector<Point_3> points;
    for(Vertex_iterator i = p.vertices_begin(); i != p.vertices_end(); ++i){
       Point_3 pt = i->point();
       points.push_back(pt);
    }
    box = CGAL::bounding_box(points.begin(), points.end());
}

void BoundingBox::display()
{
    configRender();
    glColor4fv(color.data());
    glLineWidth(1);
    glBegin(GL_LINES);
        int i = 0;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 1;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 0;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 3;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 0;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 5;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 7;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 2;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 7;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 4;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 7;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 6;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 3;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 2;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 1;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 2;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 4;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 5;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 4;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 3;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 6;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 7;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 6;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 5;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());

        i = 1;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
        i = 6;
        glVertex3d(box.vertex(i).x(), box.vertex(i).y(), box.vertex(i).z());
    glEnd();
}
