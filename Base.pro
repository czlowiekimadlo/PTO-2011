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
    src/formats/ppmformat.cpp \
    src/windows/histogramwindow.cpp \
    src/formats/jpgformat.cpp \
    src/commands/basecommand.cpp \
    src/commands/commandqueue.cpp \
    src/windows/historywindow.cpp \
    src/commands/openfilecommand.cpp \
    src/commands/histogramevencommand.cpp \
    src/windows/histogramevendialog.cpp \
    src/commands/histogramstretchcommand.cpp

HEADERS  += src/mainwindow.h \
    src/formats/imageFormat.h \
    src/imagewindow.h \
    src/formats/pbmformat.h \
    src/formats/pgmformat.h \
    src/formats/ppmformat.h \
    src/windows/histogramwindow.h \
    src/formats/jpgformat.h \
    src/commands/basecommand.h \
    src/commands/commandqueue.h \
    src/windows/historywindow.h \
    src/commands/openfilecommand.h \
    src/commands/histogramevencommand.h \
    src/windows/histogramevendialog.h \
    src/commands/histogramstretchcommand.h

FORMS    += src/mainwindow.ui \
    src/imagewindow.ui \
    src/windows/histogramwindow.ui \
    src/windows/historywindow.ui \
    src/windows/histogramevendialog.ui












































