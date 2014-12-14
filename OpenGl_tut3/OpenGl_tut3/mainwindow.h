#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include <glwidget.h>
#include <QMouseEvent>
#include <Util/mouse.h>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel* label;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
