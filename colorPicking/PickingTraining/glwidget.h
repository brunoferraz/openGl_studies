#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <iostream>
#include <stdio.h>
#include <QMouseEvent>

using namespace std;
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();

    void drawScene();

    void mouseReleaseEvent(QMouseEvent *ev);
    void hitPicking(QMouseEvent *ev);
    void colorPicking(QMouseEvent *ev);
    void drawBlock(float x, float y, float z);

signals:

public slots:

};

#endif // GLWIDGET_H
