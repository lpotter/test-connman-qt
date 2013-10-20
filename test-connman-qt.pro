#-------------------------------------------------
#
# Project created by QtCreator 2013-09-29T04:35:24
#
#-------------------------------------------------

QT       += core dbus

QT       -= gui

TARGET = test-connman-qt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lconnman-qt5
SOURCES += main.cpp
