#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T12:03:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = anise_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    connection.cpp \
    mesh.cpp \
    gate.cpp \
    jsonfilehandler.cpp \
    settingshandler.cpp \
    anisecommunicator.cpp \
    nodefactory.cpp \
    nodecatalog.cpp \
    dragwidget.cpp \
    drawobject.cpp \
    mesheditorwidget.cpp \
    data.cpp \
    dataholder.cpp \
    singletonrender.cpp


HEADERS  += mainwindow.h \
    node.h \
    connection.h \
    mesh.h \
    gate.h \
    jsonfilehandler.h \
    settingshandler.h \
    anisecommunicator.h \
    qdebugstreamredirector.h \
    anisecommunicator.h \
    nodefactory.h \
    nodecatalog.h \
    dragwidget.h \
    drawobject.h \
    mesheditorwidget.h \
    data.h \
    dataholder.h \
    singletonrender.h

FORMS    += mainwindow.ui


DESTDIR = "../build"

