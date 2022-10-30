#include "manager.h"

MineCore::Manager::Manager(uint32_t width, uint32_t height) {
  m_width = width;
  m_height = height;

  initField();
}

MineCore::Manager::~Manager() {
  delete [] m_field;
}

void MineCore::Manager::generateBombs(uint32_t bombCount) {
  uint32_t length = m_width * m_height;
  if (bombCount >= length)
    bombCount = length - 1;
  else if (bombCount < 1)
    bombCount = 1;

  std::vector<uint32_t> indexes(length);
  for (uint32_t i = 0; i < length; i++)
    indexes[i] = i;

  srand(time(nullptr));
  for (uint32_t i = 0; i < bombCount; i++) {
    uint32_t r = rand() % indexes.size();
    uint32_t index = indexes[r];
    indexes.erase(indexes.begin() + r);
    m_field[index].s.value = CellValueType::Bomb;
  }
}

void MineCore::Manager::initField() {
  uint32_t length = m_width * m_height;
  m_field = new Cell_u[length];
  for (uint32_t i = 0; i < length; i++)
    m_field[i].raw = 0;
}

void MineCore::Manager::fillValue(MineCore::CellValueType valueType) {
  uint32_t length = m_width * m_height;
  for (uint32_t i = 0; i < length; i++)
    m_field[i].s.value = valueType;
}

void MineCore::Manager::fillMask(MineCore::CellMaskType maskType) {
  uint32_t length = m_width * m_height;
  for (uint32_t i = 0; i < length; i++)
    m_field[i].s.mask = maskType;
}
