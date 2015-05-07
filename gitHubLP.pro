#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T20:54:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gitHubLP
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    dialog2.cpp \
    list.cpp \
    mainwindow.cpp \
    node.cpp \
    player.cpp \
    team.cpp

HEADERS  += dialog.h \
    dialog2.h \
    list.h \
    mainwindow.h \
    node.h \
    player.h \
    team.h

FORMS    += dialog.ui \
    dialog2.ui \
    mainwindow.ui

DISTFILES += \
    Doxyfile
