#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <eigen3/Eigen/Dense>
#include <QVector>
#include <QList>
#include <QDebug>
#include <QtAlgorithms>
#include <util.h>
#include <math.h>


using namespace std;
using namespace Eigen;
class ConvexHull
{
public:
    ConvexHull();

    void addPoint(Vector4d &p);
    QList<Vector4d> orderByAngle(QList<Vector4d> &list);
    QList<Vector4d> orderByX(QList<Vector4d> &blist);
    QList<Vector4d> findConvexHull(QList<Vector4d> &plist);

    QList<QList<Vector4d> > divideAndConquer(QList<Vector4d> &blist);
    QList<Vector4d> getTangents(QList<Vector4d> left, QList<Vector4d > right, QList<Vector4d > &tangentList);
    QList<Vector4d> getMaxMinLink(QList<Vector4d> left, QList<Vector4d > right);

    QList<Vector4d> tangentStep(QList<Vector4d> left, QList<Vector4d > right, QList<Vector4d > &tangentList);
    QList<Vector4d> tangentWalk(QList<Vector4d> left, QList<Vector4d > right, QList<Vector4d > &tangentList);

    bool tangentWalkEnds(QList<Vector4d> &lastTangentList, QList<Vector4d> &nextTangentList);

    QList<Vector4d> divConqConvexHull(QList<Vector4d> &plist);
    QList<Vector4d> joinPolygons(QList<Vector4d> left, QList<Vector4d > right);

    static int getIndexFrom(QList<Vector4d> &tangentList, int nextChoice);
};

#endif // CONVEXHULL_H
