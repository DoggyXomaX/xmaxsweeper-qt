#ifndef __GRAPHICSCONTAINER_H__
#define __GRAPHICSCONTAINER_H__

#include <QLabel>
#include <QPixmap>
#include <QWidget>

#include "graphicstemplate.h"

class GraphicsContainer {
  public:
    GraphicsContainer(const GraphicsTemplate *graphicsTemplate, float scale, QWidget *parent);
    ~GraphicsContainer();
  private:
    void updateScale(float scale);
    QLabel *m_label;
    int m_x, m_y, m_width, m_height;
    float m_scale;
};

#endif // __GRAPHICSCONTAINER_H__
