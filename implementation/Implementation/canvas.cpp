#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    resize(parent->size());
    canvasMode  = POINT;
    lineColor   = Qt::black;
    shapeColor  = Qt::black;
    polygonColor= Qt::black;
    pointColor  = Qt::black;

    pointWidth      = 1;
    pointSize       = 2;
    lineWidth       = 1;
    polygonWidth    = 1;

    lineList        =  new QList<Vector4d>;
    lineLoopList    =  new QList<Vector4d>;
    pointList       =  new QList<Vector4d>;
    polygonList     =  new QList<QList<Vector4d> >;
}
void Canvas::linkList(QList<Vector4d> &l)
{
    pointList = &l;
    pointList->pop_back();
    update();
}
void Canvas::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPen pen;

    //DRAW POINT LIST;
    if(pointList->length()>0){
        pen.setWidth(pointWidth);
        pen.setColor(pointColor);
        painter.setPen(pen);
        for(int i =0; i < pointList->length(); i++){
            painter.drawEllipse(QPoint(pointList->at(i)(0), pointList->at(i)(1)), pointSize, pointSize);
        }
    }
    //DRAW LINE LIST;
    if(lineList->length()>1){
        pen.setWidth(lineWidth);
        pen.setColor(lineColor);
        painter.setPen(pen);
        for(int i =1; i < lineList->length(); i++){
            painter.drawLine(lineList->at(i-1)(0), lineList->at(i-1)(1),lineList->at(i)(0), lineList->at(i)(1));
            i++;
        }
    }
    //DRAW LINE LOOP;
    if(lineLoopList->length()>1){
        pen.setWidth(lineLoopWidth);
        pen.setColor(lineLoopColor);
        painter.setPen(pen);
        for(int i =1; i < lineLoopList->length(); i++){
            painter.drawLine(lineLoopList->at(i-1)(0), lineLoopList->at(i-1)(1),lineLoopList->at(i)(0), lineLoopList->at(i)(1));
        }
        painter.drawLine(lineLoopList->at(lineLoopList->length()-1)(0), lineLoopList->at(lineLoopList->length()-1)(1),lineLoopList->at(0)(0), lineLoopList->at(0)(1));
    }
    //DRAW POLYGON LIST;
    if(polygonList->length()>1){
        pen.setWidth(polygonWidth);
        pen.setColor(polygonColor);
        painter.setPen(pen);
         for(int i =0; i < polygonList->length(); i++){
            QList <Vector4d> polygon = polygonList->at(i);
            for(int j=1; j<polygon.length();j++){
                painter.drawLine(polygon.at(j-1)(0), polygon.at(j-1)(1),polygon.at(j)(0), polygon.at(j)(1));
            }
            painter.drawLine(polygon.at(polygon.length()-1)(0), polygon.at(polygon.length()-1)(1),polygon.at(0)(0), polygon.at(0)(1));
         }
    }
}
