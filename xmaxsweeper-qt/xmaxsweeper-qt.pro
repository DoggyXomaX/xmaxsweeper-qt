QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/graphics/graphicscontainer.cpp \
    classes/mine/minetimer.cpp \
    components/xmaxwindow.cpp \
    headers/mine/minetimer.cpp \
    main.cpp \
    sources/graphicscontainer.cpp \
    sources/main.cpp \
    sources/xmaxwindow.cpp

HEADERS += \
    classes/graphics/graphicscontainer.h \
    classes/graphics/graphicstemplate.h \
    classes/mine/minetimer.h \
    components/xmaxwindow.h \
    headers/graphicscontainer.h \
    headers/graphicstemplate.h \
    headers/mine/minetimer.h \
    headers/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
