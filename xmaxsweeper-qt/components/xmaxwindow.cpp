#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  // Temporary 4.0f
  m_aspectScale = 12.0f;

  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(
    int(float(80) * m_aspectScale),
    int(float(62) * m_aspectScale));
  setStyleSheet("background-color: #D9B697;");

  m_leftTimer = new MineGraphics::Timer(3, 0, 14, 3, m_aspectScale, this);
  m_rightTimer = new MineGraphics::Timer(3, 0, 51, 3, m_aspectScale, this);
  m_xmaxButton = new MineGraphics::XmaxButton(35, 3, 10, m_aspectScale, this);
  m_field = new MineGraphics::Field(8, 8, 20, 19, 5, m_aspectScale, this);
}

XmaxWindow::~XmaxWindow() {
  if (MineGraphics::Timer::DigitPixmapsInitialized)
    delete [] MineGraphics::Timer::DigitPixmaps;

  if (MineGraphics::XmaxButton::PixmapsInitialized) {
    delete [] MineGraphics::XmaxButton::ButtonPixmaps;
    delete [] MineGraphics::XmaxButton::XmaxPixmaps;
  }

  if (MineGraphics::Field::CellPixmapsInitialized)
    delete [] MineGraphics::Field::CellPixmaps;

  delete m_leftTimer;
  delete m_rightTimer;
  delete m_xmaxButton;
  delete m_field;
}
