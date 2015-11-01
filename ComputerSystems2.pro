#-------------------------------------------------
#
# Project created by QtCreator 2015-10-31T09:15:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComputerSystems2
TEMPLATE = app

CONFIG += c++11
QT += webkitwidgets


SOURCES += main.cpp\
        mainwindow.cpp \
    intmatrix.cpp \
    singleunitsystem.cpp \
    unitswithlocalmemory.cpp \
    unitswithsharedmemory.cpp

HEADERS  += mainwindow.h \
    tasktypes.h \
    constants.h \
    randomintmatrixgeneration.h \
    intmatrix.h \
    singleunitsystem.h \
    unitswithlocalmemory.h \
    unitswithsharedmemory.h

FORMS    += mainwindow.ui
