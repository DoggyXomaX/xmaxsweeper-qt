#include <QApplication>
#include <QPushButton>

#include "components/xmaxwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  XmaxWindow *window = new XmaxWindow();
  window->show();

  int result = app.exec();

  delete window;

  return result;
}
