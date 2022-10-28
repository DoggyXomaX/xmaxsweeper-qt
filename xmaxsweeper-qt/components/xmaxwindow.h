#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>
#include <QMessageBox>

#include "classes/graphics/graphicscontainer.h"
#include "classes/graphics/graphicstemplate.h"

#include "classes/mine/mineborders.h"
#include "classes/mine/minetimer.h"
#include "classes/mine/minexmaxbutton.h"

const GraphicsTemplate_t DebugGraphicsTemplate[] = {
  // No comments, just copy & paste
  { ":/img/cell/masked.png", 20, 19, 5, 5, false },
  { ":/img/cell/masked.png", 20, 24, 5, 5, false },
  { ":/img/cell/masked.png", 20, 29, 5, 5, false },
  { ":/img/cell/masked.png", 20, 34, 5, 5, false },
  { ":/img/cell/masked.png", 20, 39, 5, 5, false },
  { ":/img/cell/masked.png", 20, 44, 5, 5, false },
  { ":/img/cell/masked.png", 20, 49, 5, 5, false },
  { ":/img/cell/masked.png", 20, 54, 5, 5, false },

  { ":/img/cell/masked.png", 25, 19, 5, 5, false },
  { ":/img/cell/masked.png", 25, 24, 5, 5, false },
  { ":/img/cell/masked.png", 25, 29, 5, 5, false },
  { ":/img/cell/masked.png", 25, 34, 5, 5, false },
  { ":/img/cell/masked.png", 25, 39, 5, 5, false },
  { ":/img/cell/masked.png", 25, 44, 5, 5, false },
  { ":/img/cell/masked.png", 25, 49, 5, 5, false },
  { ":/img/cell/masked.png", 25, 54, 5, 5, false },

  { ":/img/cell/masked.png", 30, 19, 5, 5, false },
  { ":/img/cell/masked.png", 30, 24, 5, 5, false },
  { ":/img/cell/masked.png", 30, 29, 5, 5, false },
  { ":/img/cell/masked.png", 30, 34, 5, 5, false },
  { ":/img/cell/masked.png", 30, 39, 5, 5, false },
  { ":/img/cell/masked.png", 30, 44, 5, 5, false },
  { ":/img/cell/masked.png", 30, 49, 5, 5, false },
  { ":/img/cell/masked.png", 30, 54, 5, 5, false },

  { ":/img/cell/masked.png", 35, 19, 5, 5, false },
  { ":/img/cell/masked.png", 35, 24, 5, 5, false },
  { ":/img/cell/masked.png", 35, 29, 5, 5, false },
  { ":/img/cell/masked.png", 35, 34, 5, 5, false },
  { ":/img/cell/masked.png", 35, 39, 5, 5, false },
  { ":/img/cell/masked.png", 35, 44, 5, 5, false },
  { ":/img/cell/masked.png", 35, 49, 5, 5, false },
  { ":/img/cell/masked.png", 35, 54, 5, 5, false },

  { ":/img/cell/masked.png", 40, 19, 5, 5, false },
  { ":/img/cell/masked.png", 40, 24, 5, 5, false },
  { ":/img/cell/masked.png", 40, 29, 5, 5, false },
  { ":/img/cell/masked.png", 40, 34, 5, 5, false },
  { ":/img/cell/masked.png", 40, 39, 5, 5, false },
  { ":/img/cell/masked.png", 40, 44, 5, 5, false },
  { ":/img/cell/masked.png", 40, 49, 5, 5, false },
  { ":/img/cell/masked.png", 40, 54, 5, 5, false },

  { ":/img/cell/masked.png", 45, 19, 5, 5, false },
  { ":/img/cell/masked.png", 45, 24, 5, 5, false },
  { ":/img/cell/masked.png", 45, 29, 5, 5, false },
  { ":/img/cell/masked.png", 45, 34, 5, 5, false },
  { ":/img/cell/masked.png", 45, 39, 5, 5, false },
  { ":/img/cell/masked.png", 45, 44, 5, 5, false },
  { ":/img/cell/masked.png", 45, 49, 5, 5, false },
  { ":/img/cell/masked.png", 45, 54, 5, 5, false },

  { ":/img/cell/masked.png", 50, 19, 5, 5, false },
  { ":/img/cell/masked.png", 50, 24, 5, 5, false },
  { ":/img/cell/masked.png", 50, 29, 5, 5, false },
  { ":/img/cell/masked.png", 50, 34, 5, 5, false },
  { ":/img/cell/masked.png", 50, 39, 5, 5, false },
  { ":/img/cell/masked.png", 50, 44, 5, 5, false },
  { ":/img/cell/masked.png", 50, 49, 5, 5, false },
  { ":/img/cell/masked.png", 50, 54, 5, 5, false },

  { ":/img/cell/masked.png", 55, 19, 5, 5, false },
  { ":/img/cell/masked.png", 55, 24, 5, 5, false },
  { ":/img/cell/masked.png", 55, 29, 5, 5, false },
  { ":/img/cell/masked.png", 55, 34, 5, 5, false },
  { ":/img/cell/masked.png", 55, 39, 5, 5, false },
  { ":/img/cell/masked.png", 55, 44, 5, 5, false },
  { ":/img/cell/masked.png", 55, 49, 5, 5, false },
  { ":/img/cell/masked.png", 55, 54, 5, 5, false },
};

const uint32_t DebugGraphicsTemplateLength = sizeof(DebugGraphicsTemplate) / sizeof(DebugGraphicsTemplate[0]);

class XmaxWindow : public QWidget {
  Q_OBJECT
  public:
    explicit XmaxWindow(QWidget *parent = nullptr);
    ~XmaxWindow();
    float getScale(void);
  private:
    float m_aspectScale;
    GraphicsContainer **m_graphics;
    MineTimer *m_leftTimer;
    MineTimer *m_rightTimer;

    MineXmaxButton *m_xmaxButton;
    // Temp
    MineBorders *m_fieldBorders;
};

#endif // __QT_XMAXWINDOW_H__
