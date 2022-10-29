#include "borders.h"

const char *MineGraphics::Borders::MineBorderPaths[] = {
  ":/img/border/left-top.png",
  ":/img/border/top.png",
  ":/img/border/right-top.png",
  ":/img/border/left.png",
  ":/img/border/right.png",
  ":/img/border/left-bottom.png",
  ":/img/border/bottom.png",
  ":/img/border/right-bottom.png",
};

MineGraphics::Borders::Borders(int x, int y, int width, int height, float scale, QWidget *parent) {
  m_borders = new QLabel*[8];
  for (int i = 0; i < 8; i++) {
    QPixmap pixmap(MineBorderPaths[i]);

    QLabel *border = new QLabel(parent);
    border->setPixmap(pixmap);
    border->setScaledContents(true);
    border->show();

    m_borders[i] = border;
  }

  setBorders(x, y, width, height, scale);
}

MineGraphics::Borders::~Borders() {
  for (int i = 0; i < 8; i++)
    delete m_borders[i];
  delete [] m_borders;
}

void MineGraphics::Borders::setPosition(int x, int y) {
  m_x = x;
  m_y = y;
  updateGeometry();
}

void MineGraphics::Borders::setSize(int width, int height) {
  m_width = width;
  m_height = height;
  updateGeometry();
}

void MineGraphics::Borders::setScale(float scale) {
  m_scale = scale;
  updateGeometry();
}

void MineGraphics::Borders::setBorders(int x, int y, int width, int height, float scale) {
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  m_scale = scale;
  updateGeometry();
}

void MineGraphics::Borders::updateGeometry() {
  int sizes[] = {
    int(2 * m_scale),
    int(m_width * m_scale),
    int(m_height * m_scale),
  };

  int cols[] = {
    int((m_x - 2) * m_scale),
    int(m_x * m_scale),
    int((m_x + m_width) * m_scale),
  };

  int rows[] = {
    int((m_y - 2) * m_scale),
    int(m_y * m_scale),
    int((m_y + m_height) * m_scale),
  };

  int tMat[4][8] = {
    { 0, 1, 2, 0, 2, 0, 1, 2 },
    { 0, 0, 0, 1, 1, 2, 2, 2 },
    { 0, 1, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 2, 2, 0, 0, 0 },
  };

  for (int i = 0; i < 8; i++)
    m_borders[i]->setGeometry(
      cols[tMat[0][i]], rows[tMat[1][i]],
      sizes[tMat[2][i]], sizes[tMat[3][i]]
    );
}
