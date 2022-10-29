#ifndef __TIMER_H__
#define __TIMER_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include "borders.h"

namespace MineGraphics {
  class Timer {
    public:
      static const uint32_t DigitWidth;
      static const uint32_t DigitHeight;
      static const char *DigitPaths[];
      static bool DigitPixmapsInitialized;
      static QPixmap *DigitPixmaps;

    public:
      Timer(uint32_t digitCount, uint32_t value, int x, int y, float scale, QWidget *parent);
      ~Timer();
      void setValue(uint32_t value);
      void setPosition(int x, int y);
      void setScale(float scale);

    private:
      void updateGeometry(void);
      void updateDigits(void);

      Borders *m_borders;
      QLabel **m_digits;
      uint32_t m_digitCount, m_value;
      int m_x, m_y;
      float m_scale;
  };
}

#endif // __TIMER_H__
