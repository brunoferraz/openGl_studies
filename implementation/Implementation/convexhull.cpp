#include "convexhull.h"

ConvexHull::ConvexHull()
{

}

void ConvexHull::addPoint(Vector4d &p)
{
//    if(!list.isEmpty()){
//        if(p(0) > list.at(maxX)(0)){
//            maxX = list.length();
//        }
//        if(p(1) > list.at(maxY)(1)){

//            maxY = list.length();
//        }
//    }
//    ConvexHull::list.push_back(p);
}

QList<Vector4d> ConvexHull::orderByAngle(QList<Vector4d> &list)
{
    Vector4d vb;
    vb << 1, 0, 0, 0;
    int maxX = 0;
    int maxY = 0;
    for(int i=0; i < list.length(); i ++)
    {
        if(!list.isEmpty()){
            if(list.at(i)(0) > list.at(maxX)(0)){
                maxX = i;
            }
            if(list.at(i)(1) > list.at(maxY)(1)){

                maxY = i;
            }
        }
    }
    for(int i=0; i < list.length(); i ++)
    {
        if(maxY != i){
            Vector4d v;
            v = list.at(i) - list.at(maxY);
            v.normalize();
            double angle = std::acos(vb.dot(v))*180/3.14;
            Vector4d vf;
            vf << list.at(i)(0), list.at(i)(1), list.at(i)(2), angle;
            list.replace(i, vf);
        }
    }
    qSort(list.begin(), list.end(), Util::toAssendingVector4d_W);
    for(int i=2; i < list.length(); i ++)
    {
        Vector4d a = list.at(i);
        Vector4d b = list.at(i-1);
        Vector4d c = list.at(i-2);
        Vector4d v1 = b-c;
        v1.normalize();
        Vector4d v2 = a-b;
        v2.normalize();
        double cosa = v1.dot(v2);
        if(cosa == 0 || cosa == 180){
            qDebug()<< "Coplanares";
        }
    }
    for(int i=0; i < list.length(); i ++)
    {
        Vector4d vf;
        vf << list.at(i)(0), list.at(i)(1), list.at(i)(2), 0;
        list.replace(i, vf);
    }
    maxY = 0;
    return list;
}

QList<Vector4d> ConvexHull::orderByX(QList<Vector4d> &blist)
{
    QList<Vector4d> list;
    list = blist.mid(0,-1);
    qSort(list.begin(), list.end(), Util::toAssendingVector4d_X);
    return list;
}

QList<Vector4d> ConvexHull::findConvexHull(QList<Vector4d> &plist)
{
        QList<Vector4d> list;
        list = orderByAngle(plist);
        QList<Vector4d> convexHull;
        Vector3d a;
        Vector3d b;
        convexHull.push_back(list.at(0));
        convexHull.push_back(list.at(1));
        for(int i= 1; i < list.length(); i++){
            int nextIndex = i+1;
            if(nextIndex>=list.length()) nextIndex = 0;
            Vector4d next = list.at(nextIndex);
            Vector4d current = convexHull.at(convexHull.length() -1);
            Vector4d last = convexHull.at(convexHull.length() -2);
            double orientation = Util::orientation(last,current,next);
            if(orientation>=0){
                int counter = 0;
                while(orientation>=0){
                    counter++;
                    orientation = -1; // Break the loop if didnt enter on if
                    if(convexHull.length()>1){
                        current = convexHull.at(convexHull.length() -1);
                        last = convexHull.at(convexHull.length() -2);
                        orientation = Util::orientation(last,current,next);
                        if(orientation>=0){
                            if(!convexHull.isEmpty()){
                                convexHull.pop_back();
                            }
                        }
                    }else{
                       qDebug()<< "end list<<<" << convexHull.length() << " <<< ";
                       qDebug()<< orientation;
                       qDebug()<< "end list";
                       orientation = -1;
                    }
                    if(counter>list.length()*100){
                        qDebug()<< "trapped in while <<<" << convexHull.length() << " <<< ";
                        qDebug()<< orientation;
                        orientation = -1;
                        qDebug()<< "trapped in while";
                    }
                 }
            }
            convexHull.push_back(next);
        }
        convexHull.pop_back();
        return convexHull;
}

QList<QList<Vector4d> > ConvexHull::divideAndConquer(QList<Vector4d> &blist)
{
    QList<Vector4d> list = blist.mid(0,-1);

    list = orderByX(list);

    QList<QList<Vector4d> > polygonList;
    int total = list.length()/2;
    int begin = 0;
    int end = total;

    QList<Vector4d> polygon;
    polygon = list.mid(begin,end);

    polygon = ConvexHull::findConvexHull(polygon);

    polygonList.push_back(polygon);
    polygon.clear();

    begin = end;
    end = list.length() -1;

    polygon = list.mid(begin,end);
    polygon = ConvexHull::findConvexHull(polygon);
    polygonList.push_back(polygon);
    return polygonList;
}

QList<Vector4d> ConvexHull::getTangents(QList<Vector4d> left, QList<Vector4d> right, QList<Vector4d > &tangentList)
{
    QList<Vector4d> tangWalk;
    //findMaxMinLink
    if(tangentList.length()<2){
        tangWalk  =  getMaxMinLink(left, right);
    }else{
        tangWalk = tangentStep(left , right, tangentList);
        //qDebug()<< " dfdsffdsfsd  <<" << tangentWalkEnds(tangentList,tangWalk);
    }
    return tangWalk;
}

QList<Vector4d> ConvexHull::getMaxMinLink(QList<Vector4d> left, QList<Vector4d> right)
{
    int maxXLeft = 0;
    int minXRight = 0;
    qSort(left.begin(), left.end(), Util::toDesendingVector4d_X);
    qSort(right.begin(), right.end(), Util::toAssendingVector4d_X);
    Vector4d maxLeft = left.at(0);
    Vector4d minRight = right.at(0);

    QList<Vector4d> MaxMinLink;
    MaxMinLink.push_back(maxLeft);
    MaxMinLink.push_back(minRight);
    return MaxMinLink;
}

QList<Vector4d> ConvexHull::tangentStep(QList<Vector4d> left, QList<Vector4d> right, QList<Vector4d > &tangentList)
{
    QList<Vector4d> tangStep;
    QList<int> tangTop;
    QList<int> tangBottom;
    if(tangentList.length() <= 2){
        //if it is the firstQuest you only have the link link
        tangTop.push_back(left.indexOf(tangentList.at(0)));
        tangTop.push_back(right.indexOf(tangentList.at(1)));
        tangBottom.push_back(left.indexOf(tangentList.at(0)));
        tangBottom.push_back(right.indexOf(tangentList.at(1)));
    }else{
        //now you have top and botton lines looking for tangents;
        tangTop.push_back(left.indexOf(tangentList.at(0)));
        tangTop.push_back(right.indexOf(tangentList.at(1)));
        tangBottom.push_back(left.indexOf(tangentList.at(2)));
        tangBottom.push_back(right.indexOf(tangentList.at(3)));
    }

    int a, vtl,vtr, b;

    //SEARCH TOP TANGENT
    a = tangTop.at(0);
    b = tangTop.at(1);
    vtl = getIndexFrom(left, a+1);
    vtr = getIndexFrom(right, b-1);
    if(Util::orientation(left.at(a), left.at(vtl),right.at(b))>0)
    {
        a = vtl;
    }
    if(Util::orientation(left.at(a), right.at(b), right.at(vtr))<0)
    {
        b = vtr;
    }
    tangStep.push_back(left.at(a));
    tangStep.push_back(right.at(b));

    //SEARCH BOTTOM TANGENT
    a = tangBottom.at(0);
    b = tangBottom.at(1);
    vtl = getIndexFrom(left, a-1);
    vtr = getIndexFrom(right, b+1);
    if(Util::orientation(left.at(a), left.at(vtl),right.at(b))<0)
    {
        a = vtl;
    }
    if(Util::orientation(left.at(a), right.at(b), right.at(vtr))>0)
    {
        b = vtr;
    }
    tangStep.push_back(left.at(a));
    tangStep.push_back(right.at(b));
    return tangStep;
}

QList<Vector4d> ConvexHull::tangentWalk(QList<Vector4d> left, QList<Vector4d> right, QList<Vector4d> &tangentList)
{
    QList<Vector4d> tangWalk = tangentStep(left, right, tangentList);
    while(!tangentWalkEnds(tangWalk, tangentList))
    {
        tangentList = tangWalk;
        tangWalk = tangentStep(left, right, tangentList);
    }
    return tangentList;
}

bool ConvexHull::tangentWalkEnds(QList<Vector4d> &lastTangentList, QList<Vector4d> &nextTangentList)
{
    bool answer = true;
    if(lastTangentList.length()!=nextTangentList.length()){
        answer = false;
    }else{
        for(int i = 0; i < lastTangentList.length(); i++)
        {
            for(int j=0; j <lastTangentList.at(i).rows(); j++){
                if(lastTangentList.at(i)(j)!=nextTangentList.at(i)(j)){
                    answer= false;
                }
            }
        }
    }
    return answer;
}

QList<Vector4d> ConvexHull::divConqConvexHull(QList<Vector4d> &plist)
{
    QList<QList<Vector4d> > polygonList = divideAndConquer(plist);
    QList<QList<Vector4d> > polyEnd = polygonList;
    while (polyEnd.at(0).length()>6) {
        polyEnd.clear();
        for(int i = 0; i < polygonList.length(); i ++){
            QList<Vector4d> poly = polygonList.at(i);
            QList<QList<Vector4d> > polyTemp = divideAndConquer(poly);
            for(int j=0; j < polyTemp.length(); j++){
                polyEnd.push_back(polyTemp.at(j));
            }
        }
        polygonList.clear();
        polygonList = polyEnd;
    }
    QList<QList<Vector4d> > newPolyList;
//    while(polygonList.length()>=2){
//        for(int i = 0; i < polygonList.length()-2; i +=2){
//            newPolyList.push_back(joinPolygons(polygonList.at(i), polygonList.at(i+1)));
//        }
//        polygonList = newPolyList;
//        newPolyList.clear();
//    }
    newPolyList.push_back(joinPolygons(polygonList.at(0),polygonList.at(1)));
    return newPolyList.at(0);
}

QList<Vector4d> ConvexHull::joinPolygons(QList<Vector4d> left, QList<Vector4d> right)
{
//    QList<Vector4d> tangents;
//    tangents = getTangents(left, right, tangents);
//    tangents = tangentWalk(left, right, tangents);
//    std::cout << "left" << std::endl;
//    Util::print_QListVector4d(left);
//    std::cout << "right" << std::endl;
//    Util::print_QListVector4d(right);
//    std::cout << "tangents" << std::endl;
//    Util::print_QListVector4d(tangents);

//    int indexBottomLeft     = left.indexOf(tangents.at(0));
//    int indexBottomRight    = right.indexOf(tangents.at(1));
//    int indexTopLeft        = left.indexOf(tangents.at(2));
//    int indexTopRight       = right.indexOf(tangents.at(3));

//    qDebug() << indexBottomLeft;
//    qDebug() << indexBottomRight;
//    qDebug() << indexTopLeft;
//    qDebug() << indexTopRight;

//    QList<Vector4d> hull;
//    hull.push_back(left.at(indexBottomLeft));
//    int index = getIndexFrom(right, indexBottomRight);
//    //percorrer o direito do bottom ate o up.
//    while(index != indexTopRight){
//        hull.push_back(right.at(index));
//        index = getIndexFrom(right, index -1);
//    }
//    //percorrer o esquerdo do up ate o bottom
//    hull.push_back(right.at(indexTopRight));
//    //hull.push_back(left.at(indexTopLeft));
//    index = indexTopLeft;
//    index = getIndexFrom(left, index);
//    while(index!= indexBottomLeft){
//        hull.push_back(left.at(index));
//        index = getIndexFrom(left, index +1);
//    }
//    std::cout << "POLIGONO   <<<>>>" << std::endl;


//    Util::print_QListVector4d(hull);
    QList<Vector4d> tangents;
    tangents = getTangents(left, right, tangents);
    tangents = tangentWalk(left, right, tangents);

    return tangents;
}

int ConvexHull::getIndexFrom(QList<Vector4d> &polygonList, int nextChoice)
{
    if(nextChoice >= polygonList.length()){
        nextChoice = 0;
    }
    if(nextChoice<0){
        nextChoice = polygonList.length()-2;
    }
    return nextChoice;
}
