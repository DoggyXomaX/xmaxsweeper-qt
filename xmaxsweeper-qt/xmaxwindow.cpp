#include "xmaxwindow.h"

XmaxWindow::XmaxWindow(QWidget *parent) : QWidget{parent} {
  setGeometry(300, 300, 300, 200);
  setStyleSheet("background-color: " BACKGROUND_COLOR ";");

  QResource::registerResource("Images.qrc");

  QPixmap *pic = new QPixmap(":/img/basic-cell.png");

  QLabel *label = new QLabel("Meow");
  label->setParent(this);
  label->setGeometry(10, 10, 50, 50);
  label->setPixmap(*pic);
  label->setScaledContents(true);

  label->show();
}
