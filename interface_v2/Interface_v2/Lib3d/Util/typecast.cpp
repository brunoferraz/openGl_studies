#include "typecast.h"

TypeCast::TypeCast()
{
}

void TypeCast::EigenMatrixToGlMatrixF(Matrix4f a, GLfloat (&b)[16])
{
    int counter = 0;
    for(int j=0; j < a.rows(); j++){
        for(int i=0; i < a.cols(); i++){
            b[counter] = a(i, j);
            counter++;
        }
    }
}

void TypeCast::GlMatrixFToEigenMatrix(GLfloat a[16], Matrix4f &b)
{
    Matrix4f m;
    int total = 16;
    for(int i= 0; i < total; i++){
        m(i) = a[i];
    }
    //m = m.transpose();
    b = m;
}

Vector4f TypeCast::indexToColor(int i)
{
    int r = i&0xFF;
    int g = (i>>8)&0xFF;
    int b = (i>>16)&0xFF;

    Vector4f v;
    v << float(r)/255.0f, float(g)/255.0f, float(b)/255.0f, 1.0f;
    return v;
}

int TypeCast::colotToIndex(int r, int g, int b)
{
    return (r)|(g<<8)|(b<<16);
}