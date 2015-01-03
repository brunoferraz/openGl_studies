#ifndef UTIL_H
#define UTIL_H
#include <eigen3/Eigen/Dense>
#include <stdio.h>
#include <iostream>
#include <QList>

using namespace Eigen;
using namespace std;
class Util
{
public:
    Util();
    static bool toAssendingVector4d_X(const Vector4d & a , const Vector4d & b ); //COMPARE X VALUE TO QSORT ASC
    static bool toDesendingVector4d_X(const Vector4d & a , const Vector4d & b ); //COMPARE Y VALUE TO QSORT DESC

    static bool toAssendingVector4d_Y(const Vector4d & a , const Vector4d & b ); //COMPARE X VALUE TO QSORT ASC
    static bool toDesendingVector4d_Y(const Vector4d & a , const Vector4d & b ); //COMPARE Y VALUE TO QSORT DESC

    static bool toAssendingVector4d_W(const Vector4d & a , const Vector4d & b ); //COMPARE X VALUE TO QSORT DESC
    static bool toDesendingVector4d_W(const Vector4d & a , const Vector4d & b ); //COMPARE Y VALUE TO QSORT DESC

    static Vector3d convertVector4dto3d(const Vector4d &v);
    static double orientation(const Vector4d &first, const Vector4d &second, const Vector4d &third);

    static void print_QListVector4d(const QList<Vector4d> &v);
};

#endif // UTIL_H
