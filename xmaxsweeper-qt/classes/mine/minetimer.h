#ifndef __MINETIMER_H__
#define __MINETIMER_H__

#include "mineborders.h"

class MineTimer {
  public:
    static const uint32_t DigitWidth;
    static const uint32_t DigitHeight;
    static const char *DigitPaths[];
    static bool DigitPixmapInitialized;
    static QPixmap *DigitPixmaps;

  public:
    MineTimer(uint32_t digitCount, uint32_t value, int x, int y, float scale, QWidget *parent);
    ~MineTimer();
    void setValue(uint32_t value);
    void setPosition(int x, int y);
    void setScale(float scale);

  private:
    void updateRect(void);
    void updateDigits(void);

    MineBorders *m_borders;
    uint32_t m_digitCount, m_value;
    int m_x, m_y;
    float m_scale;
    QLabel **m_digits;
};

#endif // __MINETIMER_H__
