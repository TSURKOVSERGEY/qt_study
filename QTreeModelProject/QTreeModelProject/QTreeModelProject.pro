#-------------------------------------------------
#
# Project created by QtCreator 2013-12-14T16:12:57
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTreeModelProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treeitem.cpp \
    treemodel.cpp \
    saxhandler.cpp \
    room.cpp \
    desktop.cpp \
    cpu.cpp \
    hdd.cpp

HEADERS  += mainwindow.h \
    treeitem.h \
    treemodel.h \
    saxhandler.h \
    room.h \
    desktop.h \
    cpu.h \
    hdd.h

FORMS    += mainwindow.ui

