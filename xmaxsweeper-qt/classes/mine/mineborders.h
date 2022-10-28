#ifndef __MINEBORDERS_H__
#define __MINEBORDERS_H__

#include <QLabel>
#include <QPixmap>

class MineBorders {
  public:
    MineBorders(int x, int y, int width, int height, float scale, QWidget *parent);
    ~MineBorders();
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setScale(float newScale);
    void setBorders(int x, int y, int width, int height, float scale);

  private:
    void updateGeometry(void);

    QLabel *m_borders[8];
    int m_x, m_y;
    int m_width, m_height;
    float m_scale;
};

#endif // __MINEBORDERS_H__
