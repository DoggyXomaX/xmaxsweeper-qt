#include "xmaxwindow.h"

void fieldResetCallback(uint32_t x, uint32_t y, void *p) {
  Q_UNUSED(x)
  Q_UNUSED(y)
  qDebug() << "Reset";

  auto wp = (XmaxWindow *)p;
  wp->setTime(0);

  auto fp = wp->getField();
  auto xmaxButton = fp->getXmaxButton();
  xmaxButton->setXmaxState(MineGraphics::XmaxType::Idle);

  auto manager = fp->getManager();
  manager->generateBombs(8);
  fp->updateField();
}

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
  m_field = new MineGraphics::Field(8, 8, 20, 19, 5, m_aspectScale, this);

  m_xmaxButton = new MineGraphics::XmaxButton(35, 3, 10, m_aspectScale, this);
  auto xmax = m_xmaxButton->getXmax();
  xmax->setCallbacks(fieldResetCallback, nullptr, nullptr);
  xmax->setPointer(this);
  m_field->setXmaxButton(m_xmaxButton);
  m_field->setFlagCounter(m_leftTimer);

  fieldResetCallback(0, 0, this); // Don't forget to update link

  m_time = 0;
  m_timer = new QTimer(this);
  connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
  m_timer->start(10);
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

  delete m_timer;
}

void XmaxWindow::setTime(uint32_t value) {
  m_time = value;
  m_rightTimer->setValue(value);
}

MineGraphics::Field *XmaxWindow::getField() {
  return m_field;
}

void XmaxWindow::timerUpdate() {
  if (m_field->getManager()->getWin() || m_field->getManager()->getLose())
    return;

  setTime(m_time + 1);
}
