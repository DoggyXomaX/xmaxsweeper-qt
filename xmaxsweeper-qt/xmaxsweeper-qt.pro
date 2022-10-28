QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/mine/minexmaxbutton.cpp \
    classes/mine/mineborders.cpp \
    classes/graphics/graphicscontainer.cpp \
    classes/mine/minetimer.cpp \
    components/xmaxwindow.cpp \
    main.cpp

HEADERS += \
    classes/graphics/graphicscontainer.h \
    classes/graphics/graphicstemplate.h \
    classes/mine/mineborders.h \
    classes/mine/minetimer.h \
    classes/mine/minexmaxbutton.h \
    components/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
