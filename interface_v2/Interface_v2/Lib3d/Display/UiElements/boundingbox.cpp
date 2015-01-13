#include "boundingbox.h"

BoundingBox::BoundingBox()
{
    color << 0.6 ,0.6 ,0.6 , 1;
}

void BoundingBox::createBoundingBox(Polyhedron& p)
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
    glColor4f(color(0), color(1), color(2), color(3));
    glPointSize(10);
    glLineWidth(1);
    float dist = 0.3;
    float op = 1 -dist;
    glBegin(GL_LINES);
        //CGAL::set_ascii_mode( std::cout);
        //vertex min
//        glVertex3d(box.xmin(), box.ymin(), box.zmin());
//        glVertex3d(box.xmin(), box.ymax() * dist, box.zmin());

//        glVertex3d(box.xmin(), box.ymin(), box.zmin());
//        glVertex3d(box.xmin(), box.ymin(), box.zmax() * dist);

//        glVertex3d(box.xmin(), box.ymin(), box.zmin());
//        glVertex3d(box.xmax() * dist, box.ymin(), box.zmin());

//        //vertex max
//        glVertex3d(box.xmax(), box.ymax(), box.zmax());
//        glVertex3d(box.xmin(), box.ymax(), box.zmax());
//        glVertex3d(box.vertex(0).x(), box.vertex(0).y(), box.vertex(0).z());
//        glVertex3d(box.vertex(1).x() * dist, box.vertex(1).y() * dist, box.vertex(1).z() * dist);

//        glVertex3d(box.vertex(0).x(), box.vertex(0).y(), box.vertex(0).z());
//        glVertex3d(box.vertex(3).x() * dist, box.vertex(3).y() * dist, box.vertex(3).z() * dist);

//        glVertex3d(box.vertex(0).x(), box.vertex(0).y(), box.vertex(0).z());
//        glVertex3d(box.vertex(5).x() * dist, box.vertex(5).y() * dist, box.vertex(5).z() * dist);

//        glVertex3d(box.vertex(5).x(), box.vertex(5).y(), box.vertex(5).z());
//        glVertex3d(box.vertex(0).x() * op, box.vertex(0).y() * op, box.vertex(0).z() * op);
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
