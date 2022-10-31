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
  m_manager = new MineCore::Manager(m_countX, m_countY);
  createField(m_countX, m_countY);
  updateGeometry();
}

MineGraphics::Field::~Field() {
  delete m_borders;
  delete m_manager;
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

void MineGraphics::Field::setCell(FieldCellTypes index, uint32_t x, uint32_t y) {
  if (x >= m_countX || y >= m_countY)
    return;

  uint32_t i = y * m_countX + x;
  switch (index) {
    case FieldCellTypes::Masked:
    case FieldCellTypes::MaskedHover:
    case FieldCellTypes::MaskedPressed:
    case FieldCellTypes::Flagged:
    case FieldCellTypes::FlaggedHover:
    case FieldCellTypes::FlaggedPressed:
    case FieldCellTypes::Question:
    case FieldCellTypes::QuestionHover:
    case FieldCellTypes::QuestionPressed: {
      uint32_t offset = uint32_t(
        (FieldCellTypes)index < FieldCellTypes::Flagged ? FieldCellTypes::Masked :
        (FieldCellTypes)index < FieldCellTypes::Question ? FieldCellTypes::Flagged :
        FieldCellTypes::Question);
      m_field[i]->setStatePixmaps(
        &CellPixmaps[offset],
        &CellPixmaps[offset + 1],
        &CellPixmaps[offset + 2]);
      break;
    }

    default: {
      m_field[i]->setStatePixmaps(nullptr, nullptr, nullptr);
      m_field[i]->setPixmap(CellPixmaps[(uint32_t)index]);
      break;
    }
  }
}

MineCore::Manager *MineGraphics::Field::getManager() {
  return m_manager;
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

void cellOpenCallback(uint32_t x, uint32_t y, void *p) {
  qDebug() << "Open: " << x << ", " << y;

  auto fp = (MineGraphics::Field*)p;
  auto manager = fp->getManager();
  manager->openCell(x, y);
  fp->updateField();
}

void cellAccordCallback(uint32_t x, uint32_t y, void *p) {
  qDebug() << "Accord: " << x << ", " << y;

  auto fp = (MineGraphics::Field*)p;
  auto manager = fp->getManager();
  manager->accordCell(x, y);
  fp->updateField();
}

void cellFlagCallback(uint32_t x, uint32_t y, void *p) {
  qDebug() << "Flag: " << x << ", " << y;

  auto fp = (MineGraphics::Field*)p;
  auto manager = fp->getManager();
  manager->flagCell(x, y);
  fp->updateField();
}

void MineGraphics::Field::createField(uint32_t countX, uint32_t countY) {
  m_countX = countX;
  m_countY = countY;

  const uint32_t length = m_countX * m_countY;
  m_field = new StateButton*[length];
  m_currentField = new MineCore::Cell_u[length];
  for (uint32_t y = 0, i = 0; y < m_countY; y++)
  for (uint32_t x = 0; x < m_countX; x++, i++) {
    m_field[i] = new StateButton;
    m_field[i]->setParent(m_parent);
    m_field[i]->setScaledContents(true);
    m_field[i]->setStatePixmaps(
      &CellPixmaps[(uint32_t)FieldCellTypes::Masked],
      &CellPixmaps[(uint32_t)FieldCellTypes::MaskedHover],
      &CellPixmaps[(uint32_t)FieldCellTypes::MaskedPressed]);
    m_field[i]->setPos(x, y);
    m_field[i]->setPointer(this);
    m_field[i]->setCallbacks(&cellOpenCallback, &cellAccordCallback, &cellFlagCallback);
    m_field[i]->show();

    m_currentField[i].s.mask = MineCore::CellMaskType::Masked;
    m_currentField[i].s.value = MineCore::CellValueType::Value0;
  }
}

void MineGraphics::Field::destroyField() {
  uint32_t length = m_countX * m_countY;
  for (uint32_t i = 0; i < length; i++)
    delete m_field[i];
  delete [] m_field;
  delete [] m_currentField;
}

void MineGraphics::Field::updateField() {
  const MineCore::Cell_u *managerField = m_manager->getField();

  for (uint32_t y = 0, i = 0; y < m_countY; y++)
  for (uint32_t x = 0; x < m_countX; x++, i++) {
    if (m_currentField[i].raw != managerField[i].raw) {
      auto cell = managerField[i];
      switch (cell.s.mask) {
        case MineCore::CellMaskType::Masked:
          setCell(FieldCellTypes::Masked, x, y);
          break;
        case MineCore::CellMaskType::Flagged:
          setCell(FieldCellTypes::Flagged, x, y);
          break;
        case MineCore::CellMaskType::Question:
          setCell(FieldCellTypes::Question, x, y);
          break;
        default:
          setCell(FieldCellTypes((uint32_t)FieldCellTypes::Value0 + (uint32_t)cell.s.value), x, y);
          break;
      }
      m_currentField[i].raw = cell.raw;
    }
  }
}
