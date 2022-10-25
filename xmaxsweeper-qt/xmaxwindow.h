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

#define CREATE_BORDER(x, y, w, h)                                                     \
  { ":/img/border/left-top.png",     (x),           (y),           2,   2,   false }, \
  { ":/img/border/top.png",          (x) + 2,       (y),           (w), 2,   false }, \
  { ":/img/border/right-top.png",    (x) + 2 + (w), (y),           2,   2,   false }, \
  { ":/img/border/left.png",         (x),           (y) + 2,       2,   (h), false }, \
  { ":/img/border/right.png",        (x) + 2 + (w), (y) + 2,       2,   (h), false }, \
  { ":/img/border/left-bottom.png",  (x),           (y) + 2 + (h), 2,   2,   false }, \
  { ":/img/border/bottom.png",       (x) + 2,       (y) + 2 + (h), (w), 2,   false }, \
  { ":/img/border/right-bottom.png", (x) + 2 + (w), (y) + 2 + (h), 2,   2,   false },

const GraphicsTemplate_t GRAPHICS_TEMPLATE[] = {
  CREATE_BORDER(12, 1, 15, 10) // Left Timer border
  CREATE_BORDER(33, 1, 10, 10) // Center border
  CREATE_BORDER(49, 1, 15, 10) // Right Timer border
  CREATE_BORDER(18, 17, 40, 40) // Bomb Field

  // Numbers
  { ":/img/number/2.png", 14, 3, 5, 10, false },
  { ":/img/number/2.png", 19, 3, 5, 10, false },
  { ":/img/number/8.png", 24, 3, 5, 10, false },
  { ":/img/number/1.png", 51, 3, 5, 10, false },
  { ":/img/number/2.png", 56, 3, 5, 10, false },
  { ":/img/number/3.png", 61, 3, 5, 10, false },

  { ":/img/cell/masked.png", 35, 3, 10, 10, false }, // Xmax cell
  { ":/img/mouse/idle.png", 36, 4, 8, 8, true },

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

const uint32_t GRAPHICS_TEMPLATE_LENGTH = sizeof(GRAPHICS_TEMPLATE) / sizeof(GRAPHICS_TEMPLATE[0]);

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
