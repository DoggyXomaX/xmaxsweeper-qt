#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  QResource::registerResource("Graphics.qrc");

  // Copy Figma design
  setFixedSize(320, 248);
  setStyleSheet("background-color: " BACKGROUND_COLOR ";");

  QPixmap *pic = new QPixmap(":/img/basic-cell.png");

  QLabel *label = new QLabel("Meow");
  label->setParent(this);
  label->setGeometry(10, 10, 50, 50);
  label->setPixmap(*pic);
  label->setScaledContents(true);

  label->show();
}
