/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *bCameraControl;
    Glwidget *widget;
    QLabel *label;
    QPushButton *bShape;
    QPushButton *bResetCam;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(548, 355);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bCameraControl = new QPushButton(centralWidget);
        bCameraControl->setObjectName(QStringLiteral("bCameraControl"));
        bCameraControl->setGeometry(QRect(440, 280, 99, 27));
        bCameraControl->setCheckable(true);
        bCameraControl->setChecked(false);
        widget = new Glwidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 421, 311));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 421, 17));
        bShape = new QPushButton(centralWidget);
        bShape->setObjectName(QStringLiteral("bShape"));
        bShape->setGeometry(QRect(440, 30, 99, 27));
        bResetCam = new QPushButton(centralWidget);
        bResetCam->setObjectName(QStringLiteral("bResetCam"));
        bResetCam->setGeometry(QRect(440, 310, 99, 27));
        bResetCam->setChecked(false);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        bCameraControl->setText(QApplication::translate("MainWindow", "Camera", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        bShape->setText(QApplication::translate("MainWindow", "Shape", 0));
        bResetCam->setText(QApplication::translate("MainWindow", "Reset Cam", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
