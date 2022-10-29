#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>
#include <QMessageBox>

#include "classes/mine/minetimer.h"
#include "classes/mine/minexmaxbutton.h"
#include "classes/mine/minefield.h"

class XmaxWindow : public QWidget {
  Q_OBJECT
  public:
    explicit XmaxWindow(QWidget *parent = nullptr);
    ~XmaxWindow();
    float getScale(void);
  private:
    float m_aspectScale;
    Mine::Timer *m_leftTimer;
    Mine::Timer *m_rightTimer;
    Mine::XmaxButton *m_xmaxButton;
    Mine::Field *m_field;
};

#endif // __QT_XMAXWINDOW_H__
