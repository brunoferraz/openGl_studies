#include "polygon.h"

Polygon::Polygon(QList<Vector4d> vList)
{
    minX = 0;
    minY = 0;
    maxX = 0;
    maxY = 0;
    currentVertexIndex = 0;
    vertexList = vList;
    if(vertexList.length()>0){
        findBounds();
        orderCirculation();
    }
}

Vector4d Polygon::getCurrentVertex()
{
    return vertexList.at(currentVertexIndex);
}

Vector4d Polygon::getVertex(int i)
{
    return vertexList.at(i);
}

Vector4d Polygon::getNextVertex()
{
    currentVertexIndex++;
    return getCurrentVertex();
}

Vector4d Polygon::getPrevVertex()
{
    currentVertexIndex--;
    return getCurrentVertex();
}

Vector4d Polygon::getNextCirculationVertex()
{
    currentVertexIndex++;
    if(currentVertexIndex >= vertexList.length()){
        currentVertexIndex = 0;
    }
    return getCurrentVertex();
}

Vector4d Polygon::getPrevCirculationVertex()
{
    currentVertexIndex--;
    if(currentVertexIndex < 0){
        currentVertexIndex = vertexList.length() -1;
    }
    return getCurrentVertex();
}

void Polygon::addVertex(Vector4d v)
{
    vertexList.push_back(v);
}

void Polygon::orderCirculation()
{
    Vector4d vb;
    vb << 1, 0, 0, 0;
    for(int i=0; i < vertexList.length(); i ++)
    {
        if(maxY != i){
            Vector4d v;
            v = vertexList.at(i) - vertexList.at(maxY);
            v.normalize();
            double angle = std::acos(vb.dot(v))*180/3.14;
            Vector4d vf;
            vf << vertexList.at(i)(0), vertexList.at(i)(1), vertexList.at(i)(2), angle;
            vertexList.replace(i, vf);
        }
    }
    qSort(vertexList.begin(), vertexList.end(), Util::toAssendingVector4d_W);
    for(int i=2; i < vertexList.length(); i ++)
    {
        Vector4d a = vertexList.at(i);
        Vector4d b = vertexList.at(i-1);
        Vector4d c = vertexList.at(i-2);
        Vector4d v1 = b-c;
        v1.normalize();
        Vector4d v2 = a-b;
        v2.normalize();
        double cosa = v1.dot(v2);
        if(cosa == 0 || cosa == 180){
            qDebug()<< "Coplanares";
        }
    }
    for(int i=0; i < vertexList.length(); i ++)
    {
        Vector4d vf;
        vf << vertexList.at(i)(0), vertexList.at(i)(1), vertexList.at(i)(2), 0;
        vertexList.replace(i, vf);
    }
    findBounds();


}

void Polygon::findBounds()
{
    //find a way to pass vertex like pointer do vertexListByX
    vertexListByX = vertexList.mid(0,-1);
    qSort(vertexListByX.begin(), vertexListByX.end(), Util::toAssendingVector4d_X);

    vertexListByY = vertexList.mid(0,-1);
    qSort(vertexListByY.begin(), vertexListByX.end(), Util::toAssendingVector4d_Y);

    //maxX =
}

void Polygon::resetCirculation()
{
    currentVertexIndex = 0;
}
