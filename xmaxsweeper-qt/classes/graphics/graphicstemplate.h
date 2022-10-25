#ifndef __GRAPHICSTEMPLATE_H__
#define __GRAPHICSTEMPLATE_H__

#include <cinttypes>

typedef struct GraphicsTemplate {
  const char *path;
  uint32_t x, y, width, height;
  bool transparent;
} GraphicsTemplate_t;

#endif // __GRAPHICSTEMPLATE_H__
