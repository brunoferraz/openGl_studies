#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T12:55:21
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = OpenGl_tut3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    Util/mouse.cpp \
    Util/Cam/cameraset.cpp \
    Util/Cam/camera.cpp

LIBS += -lGLEW -lglut -lGL -lGLU

HEADERS  += mainwindow.h \
    glwidget.h \
    Util/mouse.h \
    Util/Cam/cameraset.h \
    Util/Cam/camera.h

FORMS    += mainwindow.ui

INCLUDEPATH += Include Include/assimp Common
