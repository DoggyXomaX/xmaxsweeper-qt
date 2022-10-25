#include "graphicscontainer.h"

GraphicsContainer::GraphicsContainer(const GraphicsTemplate *graphicsTemplate, QWidget *parent) {
  m_pixmap = new QPixmap(graphicsTemplate->path);

  m_label = new QLabel();
  m_label->setGeometry(graphicsTemplate->x, graphicsTemplate->y, graphicsTemplate->width, graphicsTemplate->height);
  m_label->setParent(parent);
  m_label->setPixmap(*m_pixmap);
  m_label->setScaledContents(true);
  m_label->show();
}
