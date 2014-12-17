#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = ui->widget;

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

void MainWindow::on_bResetCam_clicked()
{
    CameraSet::currentCamera->resetCamera();
    glWidget->configScreen(glWidget->width(), glWidget->height());
    glWidget->updateGL();
}

void MainWindow::on_bCameraControl_toggled(bool checked)
{
    Interface::bCamera = checked;
}

void MainWindow::on_bShape_toggled(bool checked)
{
    Interface::bShape = checked;
}
