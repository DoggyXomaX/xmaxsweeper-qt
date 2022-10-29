#ifndef __FIELD_H__
#define __FIELD_H__

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include <cstdlib>

#include "borders.h"
#include "components/statebutton.h"

namespace Mine {
  class Field {
    public:
      static const char *CellPixmapPaths[];
      static bool CellPixmapsInitialized;
      static QPixmap *CellPixmaps;

    public:
      Field(uint32_t countX, uint32_t countY, int x, int y, int size, float scale, QWidget *parent);
      ~Field();
      void setPosition(int x, int y);
      void setSize(int size);
      void setScale(float scale);
      void setCounts(uint32_t countX, uint32_t countY);
      void setCell(uint32_t index, uint32_t x, uint32_t y);

    private:
      void updateGeometry(void);
      void createField(uint32_t countX, uint32_t countY);
      void destroyField(void);

      QWidget *m_parent;
      Borders *m_borders;
      StateButton **m_field;
      uint32_t m_countX, m_countY;

      uint32_t *m_fieldIndexes;

      int m_x, m_y;
      int m_size;
      float m_scale;
  };
}

#endif // __FIELD_H__
