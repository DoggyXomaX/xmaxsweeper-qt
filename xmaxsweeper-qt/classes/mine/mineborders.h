#ifndef __MINEBORDERS_H__
#define __MINEBORDERS_H__

#include <QLabel>
#include <QPixmap>

#define T_X      0
#define T_Y      1
#define T_WIDTH  2
#define T_HEIGHT 3

class MineBorders {
  public:
    MineBorders(int x, int y, int width, int height, float scale, QWidget *parent);
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setScale(float newScale);
    void setBorders(int x, int y, int width, int height, float scale);

  private:
    void updateBorders(void);
    int m_x, m_y;
    int m_width, m_height;
    float m_scale;
    QLabel *m_borders[8];
};

#endif // __MINEBORDERS_H__
