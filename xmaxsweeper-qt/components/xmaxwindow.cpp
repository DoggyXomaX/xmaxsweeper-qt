#include "headers/xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  // Temporary 1.0f
  m_aspectScale = 4.0f;

  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(320, 248);
  setStyleSheet("background-color: " BACKGROUND_COLOR ";");

  for (uint32_t i = 0; i < GRAPHICS_TEMPLATE_LENGTH; i++) {
    auto temp = &(GRAPHICS_TEMPLATE[i]);
    GraphicsTemplate t = {
      temp->path,
      (uint32_t)(temp->x * m_aspectScale),
      (uint32_t)(temp->y * m_aspectScale),
      (uint32_t)(temp->width * m_aspectScale),
      (uint32_t)(temp->height * m_aspectScale),
      temp->transparent,
    };

    GraphicsContainer container(&t, this);
    m_graphics.push_back(container);
  }
}
