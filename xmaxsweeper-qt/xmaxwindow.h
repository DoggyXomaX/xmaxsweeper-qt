#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>
#include <QMessageBox>

#include <vector>
using std::vector;

#include "graphicscontainer.h"
#include "graphicstemplate.h"

#define BACKGROUND_COLOR "#D9B697"

const GraphicsTemplate_t GRAPHICS_TEMPLATE[] = {
  { ":/img/basic-cell.png", 10, 10, 50, 50 }
};

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
