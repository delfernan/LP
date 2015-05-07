#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T18:21:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-p10
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog2.cpp \
    list.cpp \
    node.cpp \
    player.cpp \
    team.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog2.h \
    list.h \
    node.h \
    player.h \
    team.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui

DISTFILES += \
    Doxyfile
