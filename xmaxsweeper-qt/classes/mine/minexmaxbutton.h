#ifndef __MINEXMAXBUTTON_H__
#define __MINEXMAXBUTTON_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include "mineborders.h"
#include "components/statebutton.h"

namespace Mine {
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
      void setButtonState(uint32_t buttonState);
      void setXmaxState(uint32_t xmaxState);

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

#endif // __MINEXMAXBUTTON_H__
