#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(320, 248);
  setStyleSheet("background-color: " BACKGROUND_COLOR ";");

  GraphicsContainer testContainer(GRAPHICS_TEMPLATE, this);
  m_graphics.push_back(testContainer);
}
