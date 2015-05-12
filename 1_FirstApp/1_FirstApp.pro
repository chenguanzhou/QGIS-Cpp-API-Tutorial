#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T15:12:54
#
#-------------------------------------------------

QT       += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin

TARGET = 1_FirstApp
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

LIBS += -lqgis_core -lqgis_gui

unix{
DEFINES += CORE_EXPORT=
DEFINES += GUI_EXPORT=
}
!unix{
INCLUDEPATH += $(QGIS_ROOT)/include
DEFINES += CORE_EXPORT=__declspec(dllimport)
DEFINES += GUI_EXPORT=__declspec(dllimport)
}
