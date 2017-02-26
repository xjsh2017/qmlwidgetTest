#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T15:00:18
#
#-------------------------------------------------

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qmlwidgetTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        waveanaldatamodel.cpp

HEADERS  += mainwindow.h \
        waveanaldatamodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    $$[QT_INSTALL_QML]/icons/icons_all.qrc
