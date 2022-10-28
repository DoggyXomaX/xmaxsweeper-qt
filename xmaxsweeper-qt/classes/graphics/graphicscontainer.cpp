#include "graphicscontainer.h"

GraphicsContainer::GraphicsContainer(const GraphicsTemplate *graphicsTemplate, float scale, QWidget *parent) {
  QPixmap m_pixmap(graphicsTemplate->path);
  m_x = graphicsTemplate->x;
  m_y = graphicsTemplate->y;
  m_width = graphicsTemplate->width;
  m_height = graphicsTemplate->height;

  m_label = new QLabel(parent);
  m_label->setPixmap(m_pixmap);
  m_label->setScaledContents(true);

  if (graphicsTemplate->transparent)
    m_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
  m_label->show();

  updateScale(scale);
}

GraphicsContainer::~GraphicsContainer() {
  delete m_label;
}

void GraphicsContainer::updateScale(float newScale) {
  m_scale = newScale;
  m_label->setGeometry(
    m_x * m_scale, m_y * m_scale,
    m_width * m_scale, m_height * m_scale);
}
