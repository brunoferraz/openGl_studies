#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <canvas.h>
#include <stdio.h>
#include <iostream>
#include <QMouseEvent>
#include <eigen3/Eigen/Dense>
#include <convexhull.h>
#include <QList>
#include <QKeyEvent>
#include <polygon.h>

using namespace Eigen;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Canvas *canvas;
    Canvas *divConqCanvas;
    ConvexHull glist;
    QList<Vector4d> pointList;
    QList<Vector4d> lineList;
    QList<QList<Vector4d> > polygonList;
    QList<Vector4d> tangentList;

    void mouseReleaseEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);
    void update();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
