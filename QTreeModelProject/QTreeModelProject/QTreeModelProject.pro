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
    room_item.cpp \
    desktop_item.cpp \
    base_item.cpp \
    hdd_item.cpp \
    cpu_item.cpp

HEADERS  += mainwindow.h \
    treeitem.h \
    treemodel.h \
    saxhandler.h \
    room_item.h \
    desktop_item.h \
    base_item.h \
    hdd_item.h \
    cpu_item.h

FORMS    += mainwindow.ui

