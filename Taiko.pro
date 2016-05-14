#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T19:26:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    game.h \
    result.h

FORMS    += mainwindow.ui \
    game.ui \
    result.ui

RESOURCES += \
    pics.qrc
