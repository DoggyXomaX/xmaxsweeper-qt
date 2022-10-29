QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/mine/borders.cpp \
    classes/mine/field.cpp \
    classes/mine/timer.cpp \
    classes/mine/xmaxbutton.cpp \
    components/statebutton.cpp \
    components/xmaxwindow.cpp \
    main.cpp

HEADERS += \
    classes/mine/borders.h \
    classes/mine/field.h \
    classes/mine/minecell.h \
    classes/mine/timer.h \
    classes/mine/xmaxbutton.h \
    components/statebutton.h \
    components/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
