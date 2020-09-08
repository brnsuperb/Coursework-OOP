#-------------------------------------------------
#
# Project created by QtCreator 2016-01-05T14:38:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = kursovaya_rabota_OOP_PI41
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    auto.cpp \
    time.cpp \
    bus.cpp \
    qcustomplot.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    auto.h \
    time.h \
    bus.h \
    qcustomplot.h \
    graph.h

FORMS    += mainwindow.ui \
    graph.ui
