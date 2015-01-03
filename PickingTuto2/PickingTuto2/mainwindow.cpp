#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glView = new GLwidget(this);

    //glView->show();
    //glView->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
