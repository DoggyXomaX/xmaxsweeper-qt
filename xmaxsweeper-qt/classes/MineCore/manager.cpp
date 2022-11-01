#include "manager.h"

MineCore::Manager::Manager(uint32_t width, uint32_t height) {
  m_width = width;
  m_height = height;
  m_maskCount = 0;
  m_flagCount = 0;
  m_win = false;
  m_lose = false;

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

  m_bombCount = bombCount;
  m_flagCount = 0;
  m_maskCount = length;

  std::vector<uint32_t> indexes(length);
  for (uint32_t i = 0; i < length; i++) {
    m_field[i].raw = 0x10; // Clear field
    indexes[i] = i;
  }

  srand(time(nullptr));
  for (uint32_t i = 0; i < bombCount; i++) {
    uint32_t r = rand() % indexes.size();
    uint32_t index = indexes[r];
    indexes.erase(indexes.begin() + r);
    m_field[index].s.value = CellValueType::Bomb;
  }

  calculateBombs();

  m_win = false;
  m_lose = false;
}

void MineCore::Manager::openRecursive(int x, int y) {
  if (x < 0 || x >= int(m_width) || y < 0 || y >= int(m_height))
    return;

  uint32_t i = uint32_t(y) * m_width + uint32_t(x);
  if (m_field[i].s.mask != CellMaskType::Open) {
    m_field[i].s.mask = CellMaskType::Open;
    m_maskCount--;
    qDebug() << m_maskCount;
    if (m_maskCount == m_bombCount) {
      m_win = true;
      return;
    }
  }


  if (m_field[i].s.value == CellValueType::Value0) {
    for (int dy = -1; dy <= 1; dy++)
    for (int dx = -1; dx <= 1; dx++) {
      if (!dx && !dy)
        continue;

      int tx = x + dx;
      if (tx < 0 || tx >= int(m_width))
        continue;
      int ty = y + dy;
      if (ty < 0 || ty >= int(m_height))
        continue;
      int ti = ty * int(m_width) + tx;

      if (m_field[ti].s.mask == CellMaskType::Masked || m_field[ti].s.mask == CellMaskType::Question)
        openCell(uint32_t(tx), uint32_t(ty));
    }
  }
}

void MineCore::Manager::openCell(uint32_t x, uint32_t y) {
  if (x >= m_width || y >= m_height)
    return;

  if (m_win || m_lose)
    return;

  uint32_t i = y * m_width + x;
  if (m_field[i].s.mask == CellMaskType::Open || m_field[i].s.mask == CellMaskType::Flagged)
    return;

  if (m_field[i].s.value == CellValueType::Bomb) {
    uint32_t length = m_width * m_height;
    for (uint32_t i = 0; i < length; i++)
      if (m_field[i].s.value == CellValueType::Bomb)
        m_field[i].s.mask = CellMaskType::Open;
    m_lose = true;
    return;
  }

  openRecursive(int(x), int(y));
}

void MineCore::Manager::accordCell(uint32_t x, uint32_t y) {
  if (x >= m_width || y >= m_height)
    return;

  uint32_t i = y * m_width + x;
  if (m_field[i].s.mask != CellMaskType::Open || m_field[i].s.value == CellValueType::Bomb)
    return;

  // flagAccord ?

  uint32_t flagCount = 0;
  for (int dy = -1; dy <= 1; dy++)
  for (int dx = -1; dx <= 1; dx++) {
    if (!dx && !dy)
      continue;

    int tx = int(x) + dx;
    if (tx < 0 || tx >= int(m_width))
      continue;

    int ty = int(y) + dy;
    if (ty < 0 || ty >= int(m_height))
      continue;

    int ti = ty * int(m_width) + tx;
    if (m_field[ti].s.mask == CellMaskType::Flagged)
      flagCount++;
  }

  if (flagCount == (uint32_t)m_field[i].s.value) {
    for (int dy = -1; dy <= 1; dy++)
    for (int dx = -1; dx <= 1; dx++) {
      if (!dx && !dy)
        continue;

      int tx = int(x) + dx;
      if (tx < 0 || tx >= int(m_width))
        continue;

      int ty = int(y) + dy;
      if (ty < 0 || ty >= int(m_height))
        continue;

      int ti = ty * int(m_width) + tx;
      if (m_field[ti].s.mask != CellMaskType::Open)
        openCell(uint32_t(tx), uint32_t(ty));
    }
  }
}

void MineCore::Manager::flagCell(uint32_t x, uint32_t y) {
  if (x >= m_width || y >= m_height)
    return;

  uint32_t i = y * m_width + x;
  if (m_field[i].s.mask == CellMaskType::Open)
    return;

  switch (m_field[i].s.mask) {
    case CellMaskType::Masked:
      m_field[i].s.mask = CellMaskType::Flagged;
      m_flagCount++;
      break;
    case CellMaskType::Flagged:
      m_field[i].s.mask = CellMaskType::Question;
      m_flagCount--;
      break;
    case CellMaskType::Question:
      m_field[i].s.mask = CellMaskType::Masked;
      break;
    default:
      break;
  }
}

const MineCore::Cell_u *MineCore::Manager::getField() {
  return (const Cell_u*)m_field;
}

uint32_t MineCore::Manager::getBombCount() {
  return m_bombCount;
}

uint32_t MineCore::Manager::getFlagCount() {
  return m_flagCount;
}

bool MineCore::Manager::getWin() {
  return m_win;
}

bool MineCore::Manager::getLose() {
  return m_lose;
}

// unsafe index
void MineCore::Manager::calculateCell(uint32_t index) {
  if (m_field[index].s.value == CellValueType::Bomb)
    return;

  uint32_t x = index % m_width;
  uint32_t y = index / m_height;
  uint32_t bombCount = 0;
  for (int dy = -1; dy <= 1; dy++)
  for (int dx = -1; dx <= 1; dx++) {
    if (!dx && !dy)
      continue;

    int tx = int(x) + dx;
    if (tx < 0 || tx >= int(m_width))
      continue;

    int ty = int(y) + dy;
    if (ty < 0 || ty >= int(m_height))
      continue;

    uint32_t ti = uint32_t(ty) * m_width + uint32_t(tx);
    if (m_field[ti].s.value == CellValueType::Bomb)
      bombCount++;
  }
  m_field[index].s.value = CellValueType(bombCount);
}

void MineCore::Manager::calculateBombs() {
  uint32_t length = m_width * m_height;
//  const auto processorCount = std::thread::hardware_concurrency();
  for (uint32_t i = 0; i < length; i++)
    calculateCell(i);
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

void MineCore::Manager::print() {
  QString outputInfo("");
  for (uint32_t y = 0, i = 0; y < m_height; y++) {
    if (y)
      outputInfo += "\n";
    for (uint32_t x = 0; x < m_width; x++, i++) {
      if (x)
        outputInfo += "\t";
      outputInfo += QString::asprintf("%u|%u", uint32_t(m_field[i].s.mask), uint32_t(m_field[i].s.value));
    }
  }

  qDebug() << outputInfo;
}
