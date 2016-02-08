#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T14:44:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = main_function
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += "`Magick++-config --cppflags --cxxflags --ldflags --libs`"

SOURCES += main.cpp
