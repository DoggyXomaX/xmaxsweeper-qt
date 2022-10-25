QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    sources/graphicscontainer.cpp \
    sources/main.cpp \
    sources/xmaxwindow.cpp

HEADERS += \
    headers/graphicscontainer.h \
    headers/graphicstemplate.h \
    headers/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
