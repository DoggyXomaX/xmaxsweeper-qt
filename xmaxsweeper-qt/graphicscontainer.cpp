#include "graphicscontainer.h"

GraphicsContainer::GraphicsContainer(QString path, QWidget *parent) {
  m_pixmap.load(path);

  m_label.setScaledContents(true);
  m_label.setParent(parent);
}
