#include "field.h"

const char *MineGraphics::Field::CellPixmapPaths[] = {
  ":/img/cell/masked.png",
  ":/img/cell/masked-hover.png",
  ":/img/cell/masked-press",
  ":/img/cell/flag.png",
  ":/img/cell/flag-hover.png",
  ":/img/cell/flag-press.png",
  ":/img/cell/question.png",
  ":/img/cell/question-hover.png",
  ":/img/cell/question-press.png",

  ":/img/cell/0.png",
  ":/img/cell/1.png",
  ":/img/cell/2.png",
  ":/img/cell/3.png",
  ":/img/cell/4.png",
  ":/img/cell/5.png",
  ":/img/cell/6.png",
  ":/img/cell/7.png",
  ":/img/cell/8.png",
  ":/img/cell/bomb.png",
};
bool MineGraphics::Field::CellPixmapsInitialized = false;
QPixmap *MineGraphics::Field::CellPixmaps = nullptr;

const uint32_t CellPixmapPathsLength = sizeof(MineGraphics::Field::CellPixmapPaths) / sizeof(MineGraphics::Field::CellPixmapPaths[0]);

MineGraphics::Field::Field(uint32_t countX, uint32_t countY, int x, int y, int size, float scale, QWidget *parent) {
  m_countX = countX;
  m_countY = countY;
  m_x = x;
  m_y = y;
  m_size = size;
  m_scale = scale;
  m_parent = parent;

  if (!CellPixmapsInitialized) {
    CellPixmapsInitialized = true;
    CellPixmaps = new QPixmap[CellPixmapPathsLength];
    for (uint32_t i = 0; i < CellPixmapPathsLength; i++)
      CellPixmaps[i] = QPixmap(CellPixmapPaths[i]);
  }

  m_borders = new Borders(x, y, size, size, scale, parent);
  createField(countX, countY);
  updateGeometry();

  // Uncomment to test randomize
  for (uint32_t y = 0; y < 8; y++)
    for (uint32_t x = 0; x < 8; x++)
      setCell(rand() % CellPixmapPathsLength, x, y);
}

MineGraphics::Field::~Field() {
  delete m_borders;
  destroyField();
}

void MineGraphics::Field::setPosition(int x, int y) {
  m_x = x;
  m_y = y;
  updateGeometry();
}

void MineGraphics::Field::setSize(int size) {
  m_size = size;
  updateGeometry();
}

void MineGraphics::Field::setScale(float scale) {
  m_scale = scale;
  updateGeometry();
}

void MineGraphics::Field::setCounts(uint32_t countX, uint32_t countY) {
  // Recreate array?
  destroyField();
  createField(countX, countY);
  updateGeometry();
}

void MineGraphics::Field::setCell(uint32_t index, uint32_t x, uint32_t y) {
  if (index >= CellPixmapPathsLength)
    return;

  if (x >= m_countX || y >= m_countY)
    return;

  uint32_t i = y * m_countX + x;
  m_fieldIndexes[i] = index;

  uint32_t offset = index <= 2 ? 0 : index <= 5 ? 3 : index <= 8 ? 6 : 0;
  switch (index) {
    case 0: case 1: case 2:
    case 3: case 4: case 5:
    case 6: case 7: case 8:
      m_field[i]->setStatePixmaps(
        &CellPixmaps[offset],
        &CellPixmaps[offset + 1],
        &CellPixmaps[offset + 2]);
      break;
    default:
      m_field[i]->setStatePixmaps(nullptr, nullptr, nullptr);
      m_field[i]->setPixmap(CellPixmaps[index]);
      break;
  }
}

void MineGraphics::Field::updateGeometry() {
  m_borders->setBorders(m_x, m_y, m_size * m_countX, m_size * m_countY, m_scale);
  for (uint32_t y = 0, i = 0; y < m_countY; y++) {
    for (uint32_t x = 0; x < m_countX; x++, i++) {
      m_field[i]->setGeometry(
        int(float(m_x + x * m_size) * m_scale),
        int(float(m_y + y * m_size) * m_scale),
        int(float(m_size) * m_scale),
        int(float(m_size) * m_scale));
    }
  }
}

void MineGraphics::Field::createField(uint32_t countX, uint32_t countY) {
  m_countX = countX;
  m_countY = countY;

  const uint32_t length = m_countX * m_countY;
  m_field = new StateButton*[length];
  m_fieldIndexes = new uint32_t[length];
  for (uint32_t i = 0; i < length; i++) {
    m_field[i] = new StateButton;
    m_field[i]->setParent(m_parent);
    m_field[i]->setScaledContents(true);
    m_field[i]->setStatePixmaps(&CellPixmaps[0], &CellPixmaps[1], &CellPixmaps[2]);
    m_field[i]->show();

    m_fieldIndexes[i] = 0;
  }
}

void MineGraphics::Field::destroyField() {
  for (uint32_t i = 0; i < m_countX * m_countY; i++)
    delete m_field[i];
  delete [] m_field;
  delete [] m_fieldIndexes;
}
