#-------------------------------------------------
#
# Project created by QtCreator 2017-11-10T14:33:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGUIThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    mythread.h

FORMS    += mainwindow.ui
