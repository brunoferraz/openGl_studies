#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include <stdio.h>
#include <eigen3/Eigen/Dense>
#include <convexhull.h>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QVector>
#include <QList>
#include <QDebug>
using namespace std;
using namespace Eigen;
class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);

    static const int POINT          = 0;
    static const int LINE           = 1;
    static const int POLYGON        = 2;
    static const int POLYGON_LIST   = 3;

    int canvasMode;
    QColor pointColor;
    QColor lineColor;
    QColor lineLoopColor;
    QColor shapeColor;

    QColor polygonColor;

    int pointWidth;
    int pointSize;
    int lineWidth;
    int lineLoopWidth;
    int polygonWidth;

    QList<Vector4d> *pointList;
    QList<Vector4d> *lineList;
    QList<Vector4d> *lineLoopList;
    QList<QList<Vector4d> > *polygonList;

    void linkList(QList<Vector4d> &l);

signals:

public slots:

protected:
    //void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
};

#endif // CANVAS_H
