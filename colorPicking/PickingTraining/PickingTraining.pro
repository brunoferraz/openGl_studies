#-------------------------------------------------
#
# Project created by QtCreator 2015-01-01T16:07:06
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = PickingTraining
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGL -lGLU
