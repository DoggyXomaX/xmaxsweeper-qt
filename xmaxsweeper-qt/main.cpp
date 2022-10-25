#include <QApplication>
#include <QPushButton>
#include <QImage>

#include "xmaxwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    XmaxWindow *window = new XmaxWindow();
    window->show();

    return app.exec();
}
