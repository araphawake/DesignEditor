#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T15:56:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesignEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Zonededessin.cpp \
    trace.cpp \
    square.cpp \
    selection.cpp \
    rectangle.cpp \
    polyline.cpp \
    line.cpp \
    geometry.cpp \
    ellipse.cpp \
    circle.cpp

HEADERS  += mainwindow.h \
    Zonededessin.h \
    Transitions.h \
    trace.h \
    square.h \
    selection.h \
    rectangle.h \
    polyline.h \
    line.h \
    geometry.h \
    ellipse.h \
    circle.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    DesignEditor.pro.user
