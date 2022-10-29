#ifndef __BORDERS_H__
#define __BORDERS_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

namespace MineGraphics {
  enum class BordersTypes {
    LeftTop = 0,
    Top,
    RightTop,
    Left,
    Right,
    LeftBottom,
    Bottom,
    RightBottom,
  };

  class Borders {
    public:
      static const char *MineBorderPaths[];

    public:
      Borders(int x, int y, int width, int height, float scale, QWidget *parent);
      ~Borders();
      void setPosition(int x, int y);
      void setSize(int width, int height);
      void setScale(float newScale);
      void setBorders(int x, int y, int width, int height, float scale);

    private:
      void updateGeometry(void);

      QLabel **m_borders;
      int m_x, m_y;
      int m_width, m_height;
      float m_scale;
  };
}

#endif // __BORDERS_H__
