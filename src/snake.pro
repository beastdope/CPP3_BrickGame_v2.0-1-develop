QT+= core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Snake
TEMPLATE = app
SOURCES += brick_game/snake/main.cpp \
           brick_game/snake/snake.cpp \
           gui/desktop/snake_gui.cpp

HEADERS += brick_game/snake/snake.h

FORMS += gui/desktop/snake.ui
