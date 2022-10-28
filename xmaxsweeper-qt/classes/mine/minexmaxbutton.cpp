#include "minexmaxbutton.h"

bool MineXmaxButton::PixmapsInitialized = false;
const char *MineXmaxButton::ButtonPixmapsPaths[] = {
  ":/img/cell/masked.png",
  ":/img/cell/masked-hover.png",
  ":/img/cell/masked-press.png",
};
QPixmap *MineXmaxButton::ButtonPixmaps = nullptr;
const char *MineXmaxButton::XmaxPixmapsPaths[] = {
  ":/img/mouse/idle.png",
  ":/img/mouse/hover.png",
  ":/img/mouse/press.png",
  ":/img/mouse/win.png",
  ":/img/mouse/lose.png",
};
QPixmap *MineXmaxButton::XmaxPixmaps = nullptr;

MineXmaxButton::MineXmaxButton(int x, int y, int size, float scale, QWidget *parent) {
  m_x = x;
  m_y = y;
  m_size = size;
  m_scale = scale;

  m_borders = new MineBorders(m_x, m_y, m_size, m_size, m_scale, parent);

  if (!MineXmaxButton::PixmapsInitialized) {
    MineXmaxButton::PixmapsInitialized = true;
    MineXmaxButton::ButtonPixmaps = new QPixmap[3];
    for (int i = 0; i < 3; i++)
      MineXmaxButton::ButtonPixmaps[i] = QPixmap(MineXmaxButton::ButtonPixmapsPaths[i]);
    MineXmaxButton::XmaxPixmaps = new QPixmap[5];
    for (int i = 0; i < 5; i++)
      MineXmaxButton::XmaxPixmaps[i] = QPixmap(MineXmaxButton::XmaxPixmapsPaths[i]);
  }

  m_button = new QLabel(parent);
  m_button->setScaledContents(true);
  m_button->show();

  m_xmax = new QLabel(m_button);
  m_xmax->setScaledContents(true);
  m_xmax->show();

  updateGeometry();
}

MineXmaxButton::~MineXmaxButton() {
  delete m_borders;
  delete m_xmax;
  delete m_button;
}

void MineXmaxButton::setPosition(int x, int y) {
  m_x = x;
  m_y = y;
  updateGeometry();
}

void MineXmaxButton::setSize(int size) {
  m_size = size;
  updateGeometry();
}

void MineXmaxButton::setScale(float scale) {
  m_scale = scale;
  updateGeometry();
}

void MineXmaxButton::setButtonState(uint32_t buttonState) {
  if (buttonState > 2) // 0 - Idle, 1 - Hover, 2 - Press
    return;

  m_button->setPixmap(MineXmaxButton::ButtonPixmaps[buttonState]);
}

void MineXmaxButton::setXmaxState(uint32_t xmaxState) {
  if (xmaxState > 4) // 0 - Idle, 1 - Hover, 2 - Press, 3 - Win, 4 - Lose
    return;

  m_xmax->setPixmap(MineXmaxButton::XmaxPixmaps[xmaxState]);
}

void MineXmaxButton::updateGeometry(void) {
  m_borders->setBorders(m_x, m_y, m_size, m_size, m_scale);
  m_button->setGeometry(
    int(m_x * m_scale),
    int(m_y * m_scale),
    int(m_size * m_scale),
    int(m_size * m_scale));
  m_xmax->setGeometry(
    int(1.0f * m_scale),
    int(1.0f * m_scale),
    int(m_size * 0.8f * m_scale),
    int(m_size * 0.8f * m_scale));
}
