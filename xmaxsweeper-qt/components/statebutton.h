#ifndef __QT_MINEBUTTON_H__
#define __QT_MINEBUTTON_H__

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QMouseEvent>
#include <QEvent>
#include <QEnterEvent>
#include <QPixmap>

typedef void StateButtonCallback(uint32_t, uint32_t);

class StateButton : public QLabel {
  Q_OBJECT
  public:
    explicit StateButton(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~StateButton();
    void setStatePixmaps(QPixmap *normal, QPixmap *hover, QPixmap *press);
    void setCallbacks(StateButtonCallback *left, StateButtonCallback *middle, StateButtonCallback *right);
    void setPos(uint32_t x, uint32_t y);

  protected:
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

  private:
    uint32_t m_cellX;
    uint32_t m_cellY;

    QPixmap *m_normal;
    QPixmap *m_hover;
    QPixmap *m_press;

    StateButtonCallback *m_leftButtonClick;
    StateButtonCallback *m_middleButtonClick;
    StateButtonCallback *m_rightButtonClick;
};

#endif // __QT_MINEBUTTON_H__
