#include "graphicscontainer.h"

GraphicsContainer::GraphicsContainer(const GraphicsTemplate *graphicsTemplate, QWidget *parent) {
  QPixmap m_pixmap(graphicsTemplate->path);

  m_label = new QLabel();
  m_label->setGeometry(graphicsTemplate->x, graphicsTemplate->y, graphicsTemplate->width, graphicsTemplate->height);
  m_label->setParent(parent);
  m_label->setPixmap(m_pixmap);
  m_label->setScaledContents(true);

  if (graphicsTemplate->transparent)
    m_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
  m_label->show();
}
