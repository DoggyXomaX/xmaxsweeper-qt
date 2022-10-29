#ifndef __MINECELL_H__
#define __MINECELL_H__

union MineCell_u {
  struct MineCell_s {
    unsigned char value : 5;
    unsigned char flag : 2;
  };
  unsigned char raw;
};

#endif // __MINECELL_H__
