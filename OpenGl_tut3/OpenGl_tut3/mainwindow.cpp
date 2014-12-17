#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = ui->widget;
//    glWidget= new Glwidget(this);
//    glWidget->show();

    //label = new QLabel(this);
    Interface::viewPortLabel = ui->label;
    CameraSet::changeCam(CameraSet::LEFT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    //label->clear();
    Keyboard::keyPress(ev);
    CameraSet::keyBoardEvent();
    glWidget->configScreen(glWidget->width(), glWidget->height());
    glWidget->updateGL();
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
   Keyboard::keyRelease(ev);
}
