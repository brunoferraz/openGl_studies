#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GlWidget *wid = new GlWidget(this);
    //wid->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
