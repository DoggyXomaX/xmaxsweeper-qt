#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>
#include <QMessageBox>

#include "classes/MineGraphics/timer.h"
#include "classes/MineGraphics/xmaxbutton.h"
#include "classes/MineGraphics/field.h"

class XmaxWindow : public QWidget {
  Q_OBJECT
  public:
    explicit XmaxWindow(QWidget *parent = nullptr);
    ~XmaxWindow();
    float getScale(void);
  private:
    float m_aspectScale;
    MineGraphics::Timer *m_leftTimer;
    MineGraphics::Timer *m_rightTimer;
    MineGraphics::XmaxButton *m_xmaxButton;
    MineGraphics::Field *m_field;
};

#endif // __QT_XMAXWINDOW_H__
