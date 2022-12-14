#include "xmaxbutton.h"

bool MineGraphics::XmaxButton::PixmapsInitialized = false;
const char *MineGraphics::XmaxButton::ButtonPixmapsPaths[] = {
  ":/img/cell/masked.png",
  ":/img/cell/masked-hover.png",
  ":/img/cell/masked-press.png",
};
QPixmap *MineGraphics::XmaxButton::ButtonPixmaps = nullptr;
const char *MineGraphics::XmaxButton::XmaxPixmapsPaths[] = {
  ":/img/mouse/idle.png",
  ":/img/mouse/hover.png",
  ":/img/mouse/press.png",
  ":/img/mouse/win.png",
  ":/img/mouse/lose.png",
};
QPixmap *MineGraphics::XmaxButton::XmaxPixmaps = nullptr;

MineGraphics::XmaxButton::XmaxButton(int x, int y, int size, float scale, QWidget *parent) {
  m_x = x;
  m_y = y;
  m_size = size;
  m_scale = scale;

  m_borders = new Borders(m_x, m_y, m_size, m_size, m_scale, parent);

  if (!PixmapsInitialized) {
    PixmapsInitialized = true;
    ButtonPixmaps = new QPixmap[3];
    for (int i = 0; i < 3; i++)
      ButtonPixmaps[i] = QPixmap(ButtonPixmapsPaths[i]);
    XmaxPixmaps = new QPixmap[5];
    for (int i = 0; i < 5; i++)
      XmaxPixmaps[i] = QPixmap(XmaxPixmapsPaths[i]);
  }

  m_button = new StateButton;
  m_button->setParent(parent);
  m_button->setScaledContents(true);
  m_button->setStatePixmaps(
    &ButtonPixmaps[(uint32_t)XmaxButtonType::Masked],
    &ButtonPixmaps[(uint32_t)XmaxButtonType::MaskedHover],
    &ButtonPixmaps[(uint32_t)XmaxButtonType::MaskedPressed]);
  m_button->show();

  m_xmax = new StateButton;
  m_xmax->setParent(m_button);
  m_xmax->setScaledContents(true);
  m_xmax->setStatePixmaps(
    &XmaxPixmaps[(uint32_t)XmaxType::Idle],
    &XmaxPixmaps[(uint32_t)XmaxType::Hover],
    &XmaxPixmaps[(uint32_t)XmaxType::Pressed]);
  m_xmax->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
  m_xmax->show();

  setButtonState(XmaxButtonType::Masked);
  setXmaxState(XmaxType::Idle);
  updateGeometry();
}

MineGraphics::XmaxButton::~XmaxButton() {
  delete m_borders;
  delete m_xmax;
  delete m_button;
}

void MineGraphics::XmaxButton::setPosition(int x, int y) {
  m_x = x;
  m_y = y;
  updateGeometry();
}

void MineGraphics::XmaxButton::setSize(int size) {
  m_size = size;
  updateGeometry();
}

void MineGraphics::XmaxButton::setScale(float scale) {
  m_scale = scale;
  updateGeometry();
}

void MineGraphics::XmaxButton::setButtonState(XmaxButtonType buttonState) {
  m_button->setPixmap(ButtonPixmaps[(int)buttonState]);
}

void MineGraphics::XmaxButton::setXmaxState(XmaxType xmaxState) {
  m_xmax->setPixmapLock(xmaxState >= XmaxType::Win);
  m_xmax->setPixmap(XmaxPixmaps[(int)xmaxState]);
}

StateButton *MineGraphics::XmaxButton::getButton() {
  return m_button;
}

StateButton *MineGraphics::XmaxButton::getXmax() {
  return m_xmax;
}

void MineGraphics::XmaxButton::updateGeometry(void) {
  m_borders->setBorders(m_x, m_y, m_size, m_size, m_scale);
  m_button->setGeometry(
    int(m_x * m_scale),
    int(m_y * m_scale),
    int(m_size * m_scale),
    int(m_size * m_scale));
  m_xmax->setGeometry(
    0,
    0,
    int(float(m_size) * m_scale),
    int(float(m_size) * m_scale));
}
