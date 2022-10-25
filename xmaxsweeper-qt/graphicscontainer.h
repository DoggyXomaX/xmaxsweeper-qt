#ifndef __GRAPHICSCONTAINER_H__
#define __GRAPHICSCONTAINER_H__

#include <QLabel>
#include <QPixmap>
#include <QWidget>

class GraphicsContainer {
  public:
    GraphicsContainer(QString path, QWidget *parent);
    ~GraphicsContainer();
  private:
    QLabel m_label;
    QPixmap m_pixmap;
};

#endif // __GRAPHICSCONTAINER_H__
