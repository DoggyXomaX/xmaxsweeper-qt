#ifndef __GRAPHICSCONTAINER_H__
#define __GRAPHICSCONTAINER_H__

#include <QLabel>
#include <QPixmap>
#include <QWidget>

#include "graphicstemplate.h"

class GraphicsContainer {
  public:
    GraphicsContainer(const GraphicsTemplate *graphicsTemplate, QWidget *parent);
  private:
    QLabel *m_label;
    QPixmap *m_pixmap;
};

#endif // __GRAPHICSCONTAINER_H__
