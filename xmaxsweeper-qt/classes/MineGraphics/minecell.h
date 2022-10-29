#ifndef __MINECELL_H__
#define __MINECELL_H__

namespace Mine {
  union Cell_u {
    struct Cell_s {
      unsigned char value : 5;
      unsigned char flag : 2;
    };
    unsigned char raw;
  };
}

#endif // __MINECELL_H__
