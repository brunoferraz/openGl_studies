#-------------------------------------------------
#
# Project created by QtCreator 2015-01-03T18:14:23
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = Interface
TEMPLATE = app

LIBS += -lGLEW -lglut -lGL -lGLU
LIBS += -L/lib64 -lgmp -lCGAL

QMAKE_CXXFLAGS += -frounding-math

SOURCES += main.cpp\
        mainwindow.cpp \
    glcanvas.cpp \
    Lib3d/interface.cpp \
    Lib3d/Util/typecast.cpp \
    Lib3d/Display/Primitives/tetrahedron.cpp \
    Lib3d/Display/UiElements/boundingbox.cpp \
    Lib3d/Display/abstractobj.cpp \
    Lib3d/Display/Primitives/basichedron.cpp \
    Lib3d/View/viewport.cpp \
    Lib3d/Display/UiElements/grid.cpp


HEADERS  += mainwindow.h \
    glcanvas.h \
    Lib3d/interface.h \
    Lib3d/Util/typecast.h \
    Lib3d/Display/Primitives/tetrahedron.h \
    Lib3d/Display/UiElements/boundingbox.h \
    Lib3d/Display/abstractobj.h \
    Lib3d/Display/Primitives/basichedron.h \
    Lib3d/View/viewport.h \
    Lib3d/Display/UiElements/grid.h



FORMS    += mainwindow.ui


INCLUDEPATH += Lib3d
