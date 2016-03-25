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
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += main.cpp \
    playerentity.cpp \
    gamestage.cpp \
    enemyspawner.cpp \
    enemy.cpp

HEADERS += \
    playerentity.h \
    gamestage.h \
    enemyspawner.h \
    enemy.h
