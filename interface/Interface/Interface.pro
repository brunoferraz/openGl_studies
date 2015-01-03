#-------------------------------------------------
#
# Project created by QtCreator 2015-01-03T18:14:23
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glcanvas.cpp

HEADERS  += mainwindow.h \
    glcanvas.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGL -lGLU
