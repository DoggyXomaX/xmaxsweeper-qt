#ifndef __XMAXBUTTON_H__
#define __XMAXBUTTON_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include "borders.h"
#include "components/statebutton.h"

namespace MineGraphics {
  enum class XmaxButtonType {
    Masked = 0,
    MaskedHover,
    MaskedPressed,
  };

  enum class XmaxType {
    Idle = 0,
    Hover,
    Pressed,
    Win,
    Lose,
  };

  class XmaxButton {
    public:
      static bool PixmapsInitialized;
      static const char *ButtonPixmapsPaths[];
      static QPixmap *ButtonPixmaps;
      static const char *XmaxPixmapsPaths[];
      static QPixmap *XmaxPixmaps;

      XmaxButton(int x, int y, int size, float scale, QWidget *parent);
      ~XmaxButton();
      void setPosition(int x, int y);
      void setSize(int size);
      void setScale(float scale);
      void setButtonState(XmaxButtonType buttonState);
      void setXmaxState(XmaxType xmaxState);

    private:
      void updateGeometry(void);

      QPixmap *m_buttonPixmaps;
      QPixmap *m_xmaxPixmaps;

      Borders *m_borders;
      StateButton *m_button;
      QLabel *m_xmax;
      int m_x, m_y, m_size;
      float m_scale;
  };
}

#endif // __XMAXBUTTON_H__
