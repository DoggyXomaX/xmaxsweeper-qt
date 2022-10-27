#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  // Temporary 4.0f
  m_aspectScale = 4.0f;

  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(320, 248);
  setStyleSheet("background-color: #D9B697;");

  m_leftTimer = new MineTimer(3, 0, 14, 3, m_aspectScale, this);
  m_rightTimer = new MineTimer(3, 0, 51, 3, m_aspectScale, this);

  int tMat[4][2] = {
    { 35, 20 },
    { 3, 19 },
    { 10, 40 },
    { 10, 40 },
  };

  for (int i = 0; i < 2; i++) {
    MineBorders borders(
      tMat[T_X][i], tMat[T_Y][i],
      tMat[T_WIDTH][i], tMat[T_HEIGHT][i],
      m_aspectScale,
      this);
  }

  for (uint32_t i = 0; i < DebugGraphicsTemplateLength; i++)
    m_graphics.push_back(GraphicsContainer(&(DebugGraphicsTemplate[i]), m_aspectScale, this));
}

XmaxWindow::~XmaxWindow() {
  delete [] MineTimer::DigitPixmaps;
}
