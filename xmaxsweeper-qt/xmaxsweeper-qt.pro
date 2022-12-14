QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/MineCore/manager.cpp \
    classes/MineGraphics/borders.cpp \
    classes/MineGraphics/field.cpp \
    classes/MineGraphics/timer.cpp \
    classes/MineGraphics/xmaxbutton.cpp \
    components/statebutton.cpp \
    components/xmaxwindow.cpp \
    main.cpp

HEADERS += \
    classes/MineCore/cell.h \
    classes/MineCore/manager.h \
    classes/MineGraphics/borders.h \
    classes/MineGraphics/field.h \
    classes/MineGraphics/timer.h \
    classes/MineGraphics/xmaxbutton.h \
    components/statebutton.h \
    components/xmaxwindow.h

RESOURCES += \
  assets/Graphics.qrc
