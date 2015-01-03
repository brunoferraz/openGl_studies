#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas              = new Canvas(this);
    canvas->lineLoopWidth = 3;
    canvas->lineLoopColor = Qt::red;
    canvas->pointList   = &pointList;
    canvas->lineLoopList = &lineList;

    divConqCanvas       = new Canvas(this);
    divConqCanvas->lineColor = Qt::blue;
    divConqCanvas->lineWidth = 3;
    divConqCanvas->polygonList = &polygonList;
    divConqCanvas->lineList = &tangentList;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::LeftButton){
//        Vector4d v;
//        v<< ev->pos().x(), ev->pos().y(), 0, 0;
//        pointList.push_back(v);
//    }else{
//        lineList = glist.findConvexHull(pointList);
//    }
//    canvas->update();
    if(ev->button() == Qt::LeftButton){
//        Vector4d v;
//        v<< ev->pos().x(), ev->pos().y(), 0, 0;
//        pointList.push_back(v);
           for(int i = 0; i < 6; i ++){
                Vector4d v;
                int w;
                w = (float(std::rand()%(this->size().width() - 100))) + 50;
                int h;
                h= (float(std::rand()%(this->size().height() - 100))) + 50;
                v << w, h, 0, 0;
                pointList.push_back(v);
            }
            tangentList.clear();
            canvas->update();
    }else if(ev->button() == Qt::RightButton){
        if(pointList.length()>=3){
            lineList = glist.findConvexHull(pointList);
            polygonList = glist.divideAndConquer(pointList);
            update();
        }
    }else if(ev->button() == Qt::MiddleButton){
        pointList.clear();
        lineList.clear();
        polygonList.clear();
        tangentList.clear();
        canvas->update();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()== Qt::Key_Space){
        tangentList = glist.getTangents(polygonList.at(0), polygonList.at(1), tangentList);
    }else if(ev->key() == Qt::Key_Z){
        if(pointList.length()>=3){
            lineList = glist.findConvexHull(pointList);
            polygonList = glist.divideAndConquer(pointList);
            update();
        }
    }else if(ev->key() == Qt::Key_X){
         if(polygonList.length()>0){
                tangentList = glist.getTangents(polygonList.at(0), polygonList.at(1), tangentList);
                tangentList = glist.tangentWalk(polygonList.at(0), polygonList.at(1), tangentList);
         }
        //tangentList = glist.divConqConvexHull(pointList);
    }
    update();
}

void MainWindow::update()
{
    canvas->update();
    divConqCanvas->update();
    QMainWindow::update();
}
