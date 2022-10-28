#include "minexmaxbutton.h"

MineXmaxButton::MineXmaxButton(int x, int y, int size, float scale, QWidget *parent) {
  m_x = x;
  m_y = y;
  m_size = size;
  m_scale = scale;

  m_borders = new MineBorders(m_x, m_y, m_size, m_size, m_scale, parent);
  // m_button, m_xmax
}

MineXmaxButton::~MineXmaxButton() {
  delete m_borders;
  delete m_button;
  delete m_xmax;
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

void setButtonState(uint32_t buttonState) {
  if (buttonState > 2) // 0 - Idle, 1 - Hover, 2 - Press
    return;

  // update Pixmap of button
}

void setXmaxState(uint32_t xmaxState) {
  if (xmaxState > 4) // 0 - Idle, 1 - Hover, 2 - Press, 3 - Win, 4 - Lose
    return;

  // update Pixmap of xmax
}

void updateGeometry(void) {
  // update Geometry
}
