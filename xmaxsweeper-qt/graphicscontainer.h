#ifndef __GRAPHICSCONTAINER_H__
#define __GRAPHICSCONTAINER_H__

#include <QLabel>
#include <QPixmap>

class GraphicsContainer {
  public:
    GraphicsContainer();
    ~GraphicsContainer();
  private:
    QLabel m_label;
    QPixmap m_Pixmap;
};

#endif // __GRAPHICSCONTAINER_H__
