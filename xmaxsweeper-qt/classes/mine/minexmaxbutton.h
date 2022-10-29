#ifndef __MINEXMAXBUTTON_H__
#define __MINEXMAXBUTTON_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include "mineborders.h"

class MineXmaxButton {
  public:
    static bool PixmapsInitialized;
    static const char *ButtonPixmapsPaths[];
    static QPixmap *ButtonPixmaps;
    static const char *XmaxPixmapsPaths[];
    static QPixmap *XmaxPixmaps;

    MineXmaxButton(int x, int y, int size, float scale, QWidget *parent);
    ~MineXmaxButton();
    void setPosition(int x, int y);
    void setSize(int size);
    void setScale(float scale);
    void setButtonState(uint32_t buttonState);
    void setXmaxState(uint32_t xmaxState);

  private:
    void updateGeometry(void);

    QPixmap *m_buttonPixmaps;
    QPixmap *m_xmaxPixmaps;

    MineBorders *m_borders;
    QLabel *m_button;
    QLabel *m_xmax;
    int m_x, m_y, m_size;
    float m_scale;
};

#endif // __MINEXMAXBUTTON_H__
