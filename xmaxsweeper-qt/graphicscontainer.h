#ifndef __GRAPHICSCONTAINER_H__
#define __GRAPHICSCONTAINER_H__

#include <QLabel>
#include <QPixmap>

class GraphicsContainer {
  public:
    GraphicsContainer(QString path);
    ~GraphicsContainer();
  private:
    QLabel m_label;
    QPixmap m_pixmap;
};

#endif // __GRAPHICSCONTAINER_H__
