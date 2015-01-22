#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T15:53:20
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = InterfaceV4
TEMPLATE = app

INCLUDEPATH += Lib3d

LIBS += -lGLEW -lglut -lGL -lGLU
LIBS += -L/lib64 -lgmp -lCGAL

QMAKE_CXXFLAGS += -frounding-math

SOURCES += main.cpp\
        mainwindow.cpp \
    glcanvas.cpp \
    Lib3d/View/viewportorto.cpp \
    Lib3d/View/viewport.cpp \
    Lib3d/Util/typecast.cpp \
    Lib3d/View/viewmanager.cpp \
    Lib3d/Tools/toolmanager.cpp \
    Lib3d/Display/abstractobj.cpp \
    Lib3d/interface.cpp \
    Lib3d/Tools/tool.cpp \
    Lib3d/Tools/select.cpp \
    Lib3d/Io/mouse.cpp \
    Lib3d/Display/Primitives/tetrahedron.cpp \
    Lib3d/Display/UiElements/grid.cpp \
    Lib3d/Display/UiElements/boundingbox.cpp \
    Lib3d/Display/UiElements/axis3d.cpp \
    Lib3d/Display/UiElements/basicuiobj.cpp \
    Lib3d/Tools/cameratool.cpp \
    Lib3d/Io/keyboard.cpp \
    Lib3d/Tools/drawtool.cpp \
    Lib3d/Tools/translatetool.cpp \
    Lib3d/Display/Primitives/basicgeometry.cpp

HEADERS  += mainwindow.h \
    glcanvas.h \
    Lib3d/View/viewportorto.h \
    Lib3d/View/viewport.h \
    Lib3d/Util/typecast.h \
    Lib3d/View/viewmanager.h \
    Lib3d/Tools/toolmanager.h \
    Lib3d/Display/abstractobj.h \
    Lib3d/interface.h \
    Lib3d/Tools/tool.h \
    Lib3d/Tools/select.h \
    Lib3d/Io/mouse.h \
    Lib3d/Display/Primitives/tetrahedron.h \
    Lib3d/Display/UiElements/grid.h \
    Lib3d/Display/UiElements/boundingbox.h \
    Lib3d/Display/UiElements/axis3d.h \
    Lib3d/Display/UiElements/basicuiobj.h \
    Lib3d/Tools/cameratool.h \
    Lib3d/Io/keyboard.h \
    Lib3d/Tools/drawtool.h \
    Lib3d/Tools/translatetool.h \
    Lib3d/Display/Primitives/basicgeometry.h

FORMS    += mainwindow.ui
