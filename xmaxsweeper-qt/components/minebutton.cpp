#include "minebutton.h"

MineButton::MineButton(QWidget *parent, Qt::WindowFlags f) : QLabel(parent) {
  Q_UNUSED(f);
  this->setAttribute(Qt::WA_Hover, true);
  m_normal = nullptr;
  m_hover = nullptr;
  m_press = nullptr;
}

MineButton::~MineButton() {}

void MineButton::setStatePixmaps(QPixmap *normal, QPixmap *hover, QPixmap *press) {
  m_normal = normal;
  m_hover = hover;
  m_press = press;
  this->leaveEvent(nullptr);
}

void MineButton::enterEvent(QEnterEvent *e) {
  Q_UNUSED(e);
  if (m_hover == nullptr)
    return;
  this->setPixmap(*m_hover);
}

void MineButton::leaveEvent(QEvent *e) {
  Q_UNUSED(e);
  if (m_normal == nullptr)
    return;
  this->setPixmap(*m_normal);
}

void MineButton::mousePressEvent(QMouseEvent *e) {
  Q_UNUSED(e);
  if (m_press == nullptr)
    return;
  this->setPixmap(*m_press);
}

void MineButton::mouseReleaseEvent(QMouseEvent *e) {
  Q_UNUSED(e);
  if (m_normal == nullptr)
    return;
  this->setPixmap(*m_normal);
}
