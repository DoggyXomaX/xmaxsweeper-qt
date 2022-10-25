#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  // Temporary 4.0f
  m_aspectScale = 4.0f;

  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(320, 248);
  setStyleSheet("background-color: " BACKGROUND_COLOR ";");

//  CREATE_BORDER(12, 1, 15, 10) // Left Timer border
//  CREATE_BORDER(33, 1, 10, 10) // Center border
//  CREATE_BORDER(49, 1, 15, 10) // Right Timer border
//  CREATE_BORDER(18, 17, 40, 40) // Bomb Field

  int tMat[4][4] = {
    { 14, 35, 51, 20 },
    { 3, 3, 3, 19 },
    { 15, 10, 15, 40 },
    { 10, 10, 10, 40 },
  };

  for (int i = 0; i < 4; i++)
    MineBorders borders(
      tMat[T_X][i], tMat[T_Y][i],
      tMat[T_WIDTH][i], tMat[T_HEIGHT][i],
      m_aspectScale,
      this);

  for (uint32_t i = 0; i < DebugGraphicsTemplateLength; i++) {
    auto temp = &(DebugGraphicsTemplate[i]);
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
