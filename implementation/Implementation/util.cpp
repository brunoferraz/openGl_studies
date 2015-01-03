#include "util.h"

Util::Util()
{
}
bool Util::toAssendingVector4d_X(const Vector4d &a, const Vector4d &b)
{
    //COMPARE X VALUE TO QSORT
    return a(0) < b(0);
}

bool Util::toAssendingVector4d_Y(const Vector4d &a, const Vector4d &b)
{
    //COMPARE Y VALUE TO QSORT
    return a(1) < b(1);
}

bool Util::toDesendingVector4d_X(const Vector4d &a, const Vector4d &b)
{
    //COMPARE X VALUE TO QSORT
    return a(0) > b(0);
}

bool Util::toDesendingVector4d_Y(const Vector4d &a, const Vector4d &b)
{
    //COMPARE Y VALUE TO QSORT
    return a(1) > b(1);
}

bool Util::toAssendingVector4d_W(const Vector4d &a, const Vector4d &b)
{
    //COMPARE W VALUE TO QSORT
    return a(3) < b(3);
}

bool Util::toDesendingVector4d_W(const Vector4d &a, const Vector4d &b)
{
    //COMPARE W VALUE TO QSORT
    return a(3) > b(3);
}

Vector3d Util::convertVector4dto3d(const Vector4d &v)
{
    Vector3d nv;
    nv << v(0), v(1), v(2);
    return nv;
}

double Util::orientation(const Vector4d &first, const Vector4d &second, const Vector4d &third)
{
    Vector3d current = Util::convertVector4dto3d(second);
    Vector3d last = Util::convertVector4dto3d(first);
    Vector3d next = Util::convertVector4dto3d(third);

    Vector3d a = current - last;
    Vector3d b = next - current;

    Vector3d opVec = a.cross(b);
    return opVec(2);
}

void Util::print_QListVector4d(const QList<Vector4d> &v)
{

    for(int i = 0; i < v.length(); i++){
        std::cout << v.at(i).transpose() << std::endl;
    }

}
