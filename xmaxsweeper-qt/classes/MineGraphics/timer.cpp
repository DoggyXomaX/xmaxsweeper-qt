#include "timer.h"

const uint32_t MineGraphics::Timer::DigitWidth = 5;
const uint32_t MineGraphics::Timer::DigitHeight = 10;
const char *MineGraphics::Timer::DigitPaths[] = {
  ":/img/number/0.png",
  ":/img/number/1.png",
  ":/img/number/2.png",
  ":/img/number/3.png",
  ":/img/number/4.png",
  ":/img/number/5.png",
  ":/img/number/6.png",
  ":/img/number/7.png",
  ":/img/number/8.png",
  ":/img/number/9.png",
};
bool MineGraphics::Timer::DigitPixmapsInitialized = false;
QPixmap *MineGraphics::Timer::DigitPixmaps = nullptr;

MineGraphics::Timer::Timer(
    uint32_t digitCount, uint32_t value,
    int x, int y,
    float scale,
    QWidget *parent)
{
  m_digitCount = digitCount;
  m_value = value;
  m_x = x;
  m_y = y;
  m_scale = scale;

  m_borders = new Borders(
    m_x, m_y,
    DigitWidth * m_digitCount, DigitHeight,
    m_scale,
    parent);

  if (!DigitPixmapsInitialized) {
    DigitPixmapsInitialized = true;
    DigitPixmaps = new QPixmap[10];
    for (int i = 0; i < 10; i++)
      DigitPixmaps[i] = QPixmap(DigitPaths[i]);
  }

  m_digits = new QLabel*[m_digitCount];
  for (uint32_t i = 0; i < m_digitCount; i++) {
    m_digits[i] = new QLabel(parent);
    m_digits[i]->setScaledContents(true);
  }

  updateGeometry();
  updateDigits();
}

MineGraphics::Timer::~Timer() {
  delete m_borders;
  for (uint32_t i = 0; i < m_digitCount; i++)
    delete m_digits[i];
  delete [] m_digits;
}

void MineGraphics::Timer::setValue(uint32_t value) {
  m_value = value;
  updateDigits();
}

void MineGraphics::Timer::setPosition(int x, int y) {
  m_x = x;
  m_y = y;
  updateGeometry();
}

void MineGraphics::Timer::setScale(float scale) {
  m_scale = scale;
  updateGeometry();
}

void MineGraphics::Timer::updateDigits() {
  qDebug() << "m_digitCount: " << m_digitCount;
  uint32_t divider = uint32_t(powf(10, m_digitCount));
  uint32_t digitValue = m_value % divider;
  for (uint32_t i = 0 ; i < m_digitCount; i++) {
    int digit = digitValue % 10;
    digitValue /= 10;
    m_digits[m_digitCount - i - 1]->setPixmap(DigitPixmaps[digit]);
  }
}

void MineGraphics::Timer::updateGeometry() {
  m_borders->setBorders(m_x, m_y, DigitWidth * m_digitCount, DigitHeight, m_scale);
  for (uint32_t i = 0; i < m_digitCount; i++)
    m_digits[i]->setGeometry(
      int((m_x + i * DigitWidth) * m_scale),
      int(m_y * m_scale),
      int(DigitWidth * m_scale),
      int(DigitHeight * m_scale));
}
