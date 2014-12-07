#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T21:16:35
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = OpenGlConfig
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

LIBS += -lGLEW -lglut -lGL -lGLU

INCLUDEPATH += Include Include/assimp
