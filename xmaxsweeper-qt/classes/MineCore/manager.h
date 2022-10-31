#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <cinttypes>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include "cell.h"

#include <QDebug>
#include <QString>

namespace MineCore {
  class Manager {
    public:
      Manager(uint32_t width, uint32_t height);
      ~Manager();
      void generateBombs(uint32_t bombCount);
      void openCell(uint32_t x, uint32_t y);
      void accordCell(uint32_t x, uint32_t y);
      void flagCell(uint32_t x, uint32_t y);
      const Cell_u *getField(void);
      uint32_t getLose(void);
      uint32_t getWin(void);

    private:
      void calculateCell(uint32_t index);
      void calculateBombs(void);
      void fillValue(CellValueType valueType);
      void fillMask(CellMaskType maskType);
      void initField(void);
      void openRecursive(int x, int y);
      void print(void);

      Cell_u *m_field;
      uint32_t m_width;
      uint32_t m_height;
      uint32_t m_bombCount;

      uint32_t m_maskCount;
      bool m_win;
      bool m_lose;
  };
}

#endif // __MANAGER_H__
