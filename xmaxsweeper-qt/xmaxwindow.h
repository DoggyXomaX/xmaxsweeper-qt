#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>

#include <vector>
using std::vector;

#include "graphicscontainer.h"

#define BACKGROUND_COLOR "#D9B697"

class XmaxWindow : public QWidget {
  Q_OBJECT
  public:
    explicit XmaxWindow(QWidget *parent = nullptr);
    float getScale(void);
  private:
    float m_aspectScale;
    vector<GraphicsContainer> m_graphics;
};

#endif // __QT_XMAXWINDOW_H__
