#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include <Eigen/Dense>
#include <iostream>
#include <stdio.h>
#include <util.h>
#include <QDebug>

using namespace Eigen;
using namespace std;


class Polygon
{
public:
    Polygon(QList<Vector4d> vList);
    QList<Vector4d> vertexList;
    QList<Vector4d *> vertexListByX;
    QList<Vector4d *> vertexListByY;

    int currentVertexIndex;
    int maxX;
    int minX;
    int maxY;
    int minY;


    Vector4d getCurrentVertex();
    Vector4d getVertex(int i);

    Vector4d getNextVertex();
    Vector4d getPrevVertex();

    Vector4d getNextCirculationVertex();
    Vector4d getPrevCirculationVertex();

    void addVertex(Vector4d v);
    void orderCirculation();
    void findBounds();
    void resetCirculation();
};

#endif // POLYGON_H
