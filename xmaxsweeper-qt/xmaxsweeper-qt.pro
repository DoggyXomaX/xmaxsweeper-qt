QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/mine/minexmaxbutton.cpp \
    classes/mine/mineborders.cpp \
    classes/mine/minetimer.cpp \
    classes/mine/minefield.cpp \
    components/minebutton.cpp \
    components/xmaxwindow.cpp \
    main.cpp

HEADERS += \
    classes/mine/minecell.h \
    classes/mine/mineborders.h \
    classes/mine/minetimer.h \
    classes/mine/minexmaxbutton.h \
    classes/mine/minefield.h \
    components/minebutton.h \
    components/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
