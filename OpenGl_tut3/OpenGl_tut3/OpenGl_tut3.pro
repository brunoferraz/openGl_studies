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
    Util/Cam/camera.cpp \
    Util/Cam/cameraortho.cpp \
    Display/displaylist.cpp \
    Display/Object3d/object3d.cpp \
    Display/Object3d/cube.cpp \
    Display/Object3d/tetrahedron.cpp \
    Display/Object3d/sphere.cpp \
    Display/InterfaceElements/grid.cpp \
    Util/keyboard.cpp \
    Display/interface.cpp

LIBS += -lGLEW -lglut -lGL -lGLU
LIBS += -L/lib64 -lgmp -lCGAL

QMAKE_CXXFLAGS += -frounding-math

HEADERS  += mainwindow.h \
    glwidget.h \
    Util/mouse.h \
    Util/Cam/cameraset.h \
    Util/Cam/camera.h \
    Util/Cam/cameraortho.h \
    Display/displaylist.h \
    Display/Object3d/object3d.h \
    Display/Object3d/cube.h \
    Display/Object3d/tetrahedron.h \
    Display/Object3d/sphere.h \
    Display/InterfaceElements/grid.h \
    Util/keyboard.h \
    Display/interface.h

FORMS    += mainwindow.ui

INCLUDEPATH += Include Include/assimp Common
