#include "statebutton.h"

StateButton::StateButton(QWidget *parent, Qt::WindowFlags f) : QLabel(parent) {
  Q_UNUSED(f);
  this->setAttribute(Qt::WA_Hover, true);
  m_normal = nullptr;
  m_hover = nullptr;
  m_press = nullptr;
}

StateButton::~StateButton() {}

void StateButton::setStatePixmaps(QPixmap *normal, QPixmap *hover, QPixmap *press) {
  m_normal = normal;
  m_hover = hover;
  m_press = press;
  this->leaveEvent(nullptr);
}

void StateButton::enterEvent(QEnterEvent *e) {
  Q_UNUSED(e);
  if (m_hover == nullptr)
    return;
  this->setPixmap(*m_hover);
}

void StateButton::leaveEvent(QEvent *e) {
  Q_UNUSED(e);
  if (m_normal == nullptr)
    return;
  this->setPixmap(*m_normal);
}

void StateButton::mousePressEvent(QMouseEvent *e) {
  Q_UNUSED(e);
  if (e->button() != Qt::LeftButton)
    return;
  if (m_press == nullptr)
    return;
  this->setPixmap(*m_press);
}

void StateButton::mouseReleaseEvent(QMouseEvent *e) {
  Q_UNUSED(e);
  if (e->button() != Qt::LeftButton)
    return;
  if (m_normal == nullptr)
    return;
  this->setPixmap(*m_normal);
}
