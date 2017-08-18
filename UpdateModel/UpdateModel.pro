#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T11:20:12
#
#-------------------------------------------------

QT       += core gui
QT       += network

#CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UpdateModel
TEMPLATE = app

#win32:QMAKE_LFLAGS += -shared

SOURCES += main.cpp\
        updatemodel.cpp \
    AutoUpdate/loadingbar.cpp \
    AutoUpdate/updatemanager.cpp \
    AutoUpdate/OS_Functions.cpp

HEADERS  += updatemodel.h \
    AutoUpdate/loadingbar.h \
    AutoUpdate/updateentry.h \
    AutoUpdate/updatemanager.h \
    AutoUpdate/OS_Functions.h

FORMS    += updatemodel.ui
