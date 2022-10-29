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
  m_xmaxButton = new MineXmaxButton(35, 3, 10, m_aspectScale, this);
  m_field = new MineField(8, 8, 20, 19, 5, m_aspectScale, this);
}

XmaxWindow::~XmaxWindow() {
  if (MineTimer::DigitPixmapsInitialized)
    delete [] MineTimer::DigitPixmaps;

  if (MineXmaxButton::PixmapsInitialized) {
    delete [] MineXmaxButton::ButtonPixmaps;
    delete [] MineXmaxButton::XmaxPixmaps;
  }

  if (MineField::CellPixmapsInitialized)
    delete [] MineField::CellPixmaps;

  delete m_leftTimer;
  delete m_rightTimer;
  delete m_xmaxButton;
  delete m_field;
}
