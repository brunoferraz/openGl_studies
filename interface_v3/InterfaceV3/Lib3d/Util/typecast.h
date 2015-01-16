#ifndef TYPECAST_H
#define TYPECAST_H

#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>

//using namespace Eigen;
using namespace std;
class TypeCast
{
public:
    TypeCast();
    static void EigenMatrixToGlMatrixF(Eigen::Matrix4f a, GLfloat (&b)[16]);
    static void GlMatrixFToEigenMatrix(GLfloat a[16], Eigen::Matrix4f &b);

    static Eigen::Vector4f indexToColor(int i);
    static int colorToIndex(int r, int g, int b);

    static void EigenToGLfloat(Eigen::Vector4f a, GLfloat (&b)[4]);
    static void copyColor(GLfloat (&a)[4], GLfloat (&b)[4]);
};

#endif // TYPECAST_H
