#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T21:22:38
#
#-------------------------------------------------

QT       += core gui serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testinterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    serialbt.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    serialbt.h

FORMS    += mainwindow.ui
