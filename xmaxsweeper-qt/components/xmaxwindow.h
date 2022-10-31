#ifndef __QT_XMAXWINDOW_H__
#define __QT_XMAXWINDOW_H__

#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QWidget>
#include <QMessageBox>
#include <QTimer>

#include "classes/MineGraphics/timer.h"
#include "classes/MineGraphics/xmaxbutton.h"
#include "classes/MineGraphics/field.h"

class XmaxWindow : public QWidget {
  Q_OBJECT
  public:
    explicit XmaxWindow(QWidget *parent = nullptr);
    ~XmaxWindow();
    void setTime(uint32_t value);
    float getScale(void);
    MineGraphics::Field *getField(void);

  private:
    float m_aspectScale;
    MineGraphics::Timer *m_leftTimer;
    MineGraphics::Timer *m_rightTimer;
    MineGraphics::XmaxButton *m_xmaxButton;
    MineGraphics::Field *m_field;
    QTimer *m_timer;
    uint32_t m_time;

  public slots:
    void timerUpdate(void);
};

#endif // __QT_XMAXWINDOW_H__
