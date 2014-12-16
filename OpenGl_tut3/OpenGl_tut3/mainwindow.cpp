#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("  Perspective");
    label->show();

    glWidget= new Glwidget(this);
    glWidget->show();

    Interface::viewPortLabel = label;
    //Interface::setviewPortLabel(label);
    //Interface::setviewPortLabel(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    Keyboard::keyPress(ev);
    CameraSet::keyBoardEvent();
    glWidget->configScreen(glWidget->width(), glWidget->height());
    glWidget->updateGL();
    //glWidget->update();
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
   Keyboard::keyRelease(ev);
}
