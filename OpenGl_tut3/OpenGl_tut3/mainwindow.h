#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include <glwidget.h>
#include <QMouseEvent>
#include <Util/mouse.h>
#include <QKeyEvent>
#include <QLabel>
#include <Util/keyboard.h>
#include <Util/Cam/cameraset.h>
#include <Display/interface.h>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Interface inter;
    QLabel* label;

    Glwidget *glWidget;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    void update();
private slots:

    void on_bResetCam_clicked();
    void on_bCameraControl_toggled(bool checked);
    void on_bShape_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
