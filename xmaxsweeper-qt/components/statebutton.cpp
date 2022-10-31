#include "statebutton.h"

StateButton::StateButton(QWidget *parent, Qt::WindowFlags f) : QLabel(parent) {
  Q_UNUSED(f);
  this->setAttribute(Qt::WA_Hover, true);
  m_pixmapLocked = false;
  m_normal = nullptr;
  m_hover = nullptr;
  m_press = nullptr;

  m_leftButtonClick = nullptr;
  m_middleButtonClick = nullptr;
  m_rightButtonClick = nullptr;

  m_cellX = 0;
  m_cellY = 0;
}

StateButton::~StateButton() {}

void StateButton::setStatePixmaps(QPixmap *normal, QPixmap *hover, QPixmap *press) {
  m_normal = normal;
  m_hover = hover;
  m_press = press;
  this->leaveEvent(nullptr);
}

void StateButton::setCallbacks(StateButtonCallback *left, StateButtonCallback *middle, StateButtonCallback *right) {
  m_leftButtonClick = left;
  m_middleButtonClick = middle;
  m_rightButtonClick = right;
}

void StateButton::setPos(uint32_t x, uint32_t y) {
  m_cellX = x;
  m_cellY = y;
}

void StateButton::setPixmapLock(bool value) {
  m_pixmapLocked = value;
}

void StateButton::enterEvent(QEnterEvent *e) {
  Q_UNUSED(e)
  if (m_hover && !m_pixmapLocked)
    this->setPixmap(*m_hover);
}

void StateButton::leaveEvent(QEvent *e) {
  Q_UNUSED(e)
  if (m_normal && !m_pixmapLocked)
    this->setPixmap(*m_normal);
}

void StateButton::mousePressEvent(QMouseEvent *e) {
  auto button = e->button();
  if (button == Qt::LeftButton && m_leftButtonClick)
    m_leftButtonClick(m_cellX, m_cellY);
  else if (button == Qt::MiddleButton && m_middleButtonClick)
    m_middleButtonClick(m_cellX, m_cellY);
  else if (button == Qt::RightButton && m_rightButtonClick)
    m_rightButtonClick(m_cellX, m_cellY);

  if (button == Qt::LeftButton && m_press && !m_pixmapLocked)
    this->setPixmap(*m_press);
}

void StateButton::mouseReleaseEvent(QMouseEvent *e) {
  if (e->button() == Qt::LeftButton && m_normal && !m_pixmapLocked)
    this->setPixmap(*m_normal);
}
