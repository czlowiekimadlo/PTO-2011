#-------------------------------------------------
#
# Project created by QtCreator 2011-10-04T23:45:15
#
#-------------------------------------------------

QT       += core gui

TARGET = Base
TEMPLATE = app


SOURCES += main.cpp\
        src/mainwindow.cpp \
    src/formats/imageFormat.cpp \
    src/imagewindow.cpp \
    src/formats/pbmformat.cpp \
    src/formats/pgmformat.cpp \
    src/formats/ppmformat.cpp

HEADERS  += src/mainwindow.h \
    src/formats/imageFormat.h \
    src/imagewindow.h \
    src/formats/pbmformat.h \
    src/formats/pgmformat.h \
    src/formats/ppmformat.h

FORMS    += src/mainwindow.ui \
    src/imagewindow.ui



















