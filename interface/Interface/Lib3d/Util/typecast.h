#ifndef TYPECAST_H
#define TYPECAST_H

#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;
class TypeCast
{
public:
    TypeCast();
    static void EigenMatrixToGlMatrixF(Matrix4f a, GLfloat (&b)[16]);
    static void GlMatrixFToEigenMatrix(GLfloat a[16], Matrix4f &b);
};

#endif // TYPECAST_H
