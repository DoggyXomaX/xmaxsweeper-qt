#include "manager.h"

MineCore::Manager::Manager(uint32_t width, uint32_t height) {
  m_width = width;
  m_height = height;

  initField();
}

MineCore::Manager::~Manager() {
  delete [] m_field;
}

void MineCore::Manager::initField() {
  uint32_t length = m_width * m_height;
  m_field = new Cell_u[length];
  for (uint32_t i = 0; i < length; i++)
    m_field[i].raw = 0;
}
