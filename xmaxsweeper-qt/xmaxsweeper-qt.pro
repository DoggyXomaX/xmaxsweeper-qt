QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    classes/graphics/graphicscontainer.cpp \
    classes/mine/minetimer.cpp \
    components/xmaxwindow.cpp

HEADERS += \
    classes/graphics/graphicscontainer.h \
    classes/graphics/graphicstemplate.h \
    classes/mine/minetimer.h \
    components/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
