#-------------------------------------------------
#
# Project created by QtCreator 2016-03-25T19:19:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = BallNMouse
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++14

TEMPLATE = app


SOURCES += main.cpp \
    playerentity.cpp \
    gamestage.cpp

HEADERS += \
    playerentity.h \
    gamestage.h