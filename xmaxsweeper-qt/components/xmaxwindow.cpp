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

  m_xmaxBorders = new MineBorders(35, 3, 10, 10, m_aspectScale, this);
  m_fieldBorders = new MineBorders(20, 19, 40, 40, m_aspectScale, this);

  m_graphics = new GraphicsContainer*[DebugGraphicsTemplateLength];
  for (uint32_t i = 0; i < DebugGraphicsTemplateLength; i++)
    m_graphics[i] = new GraphicsContainer(&(DebugGraphicsTemplate[i]), m_aspectScale, this);
}

XmaxWindow::~XmaxWindow() {
  if (MineTimer::DigitPixmapsInitialized)
    delete [] MineTimer::DigitPixmaps;

  if (MineXmaxButton::PixmapsInitialized) {
    delete [] MineXmaxButton::ButtonPixmaps;
    delete [] MineXmaxButton::XmaxPixmaps;
  }

  delete m_leftTimer;
  delete m_rightTimer;
  delete m_xmaxBorders;
  delete m_fieldBorders;

  for (uint32_t i = 0; i < DebugGraphicsTemplateLength; i++)
    delete m_graphics[i];
  delete m_graphics;
}
