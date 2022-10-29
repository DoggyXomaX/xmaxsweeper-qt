#ifndef __MINECELL_H__
#define __MINECELL_H__

#include <cinttypes>

namespace MineCore {
  enum class CellFlagType {
    Open = 0,
    Masked,
    Flagged,
    Question,
  };

  enum class CellValueType {
    Value0 = 0,
    Value1,
    Value2,
    Value3,
    Value4,
    Value5,
    Value6,
    Value7,
    Value8,
    Bomb,
  };

  typedef struct Cell_s {
    CellValueType value : 4;
    CellFlagType flag : 2;
  } Cell_t;

  union Cell_u {
    Cell_t s;
    unsigned char raw;
  };
}

#endif // __MINECELL_H__
