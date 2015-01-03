#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = ui->widget;
    Interface::canvas = glWidget;

    Interface::viewPortLabel = ui->label;
    CameraSet::changeCam(CameraSet::PERSPECTIVE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    Interface::KeyboardPressEvent(ev);
    update();
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    Keyboard::keyRelease(ev);
}

void MainWindow::update()
{
    glWidget->configScreen(glWidget->width(), glWidget->height());
    glWidget->updateGL();
    QWidget::update();
}

void MainWindow::on_bResetCam_clicked()
{
    CameraSet::currentCamera->resetCamera();
    update();
}

void MainWindow::on_bCameraControl_toggled(bool checked)
{
    Interface::bCamera = checked;
}

void MainWindow::on_bShape_toggled(bool checked)
{
    Interface::bShape = checked;
}
