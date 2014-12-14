#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Glwidget *wid = new Glwidget(this);
    wid->show();
    label = new QLabel(this);
    label->setText("  Perspective");
    label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
