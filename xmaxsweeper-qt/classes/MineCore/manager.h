#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <cinttypes>
#include "cell.h"

namespace MineCore {
  class Manager {
    public:
      Manager(uint32_t width, uint32_t height);
      ~Manager();

    private:
      void initField();

      Cell_u *m_field;
      uint32_t m_width;
      uint32_t m_height;
      uint32_t m_bombCount;
  };
}

#endif // __MANAGER_H__
