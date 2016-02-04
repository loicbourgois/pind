QT += core
QT -= gui

QMAKE_CXXFLAGS += -std=c++0x

TARGET = pind
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    display.cpp \
    map.cpp \
    snake.cpp \
    game.cpp

HEADERS += \
    display.hpp \
    map.hpp \
    snake.hpp \
    game.hpp

DISTFILES += \
    maps/0.map

