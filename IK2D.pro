#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T15:30:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IK2D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    arm.cpp \
    joint.cpp \
    util.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    arm.h \
    joint.h \
    util.h

FORMS    += mainwindow.ui
