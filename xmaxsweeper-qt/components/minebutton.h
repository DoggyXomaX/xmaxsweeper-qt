#ifndef __QT_MINEBUTTON_H__
#define __QT_MINEBUTTON_H__

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QMouseEvent>
#include <QEvent>
#include <QEnterEvent>
#include <QPixmap>

class MineButton : public QLabel {
  Q_OBJECT
  public:
    explicit MineButton(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~MineButton();
    void setStatePixmaps(QPixmap *normal, QPixmap *hover, QPixmap *press);

  protected:
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

  private:
    QPixmap *m_normal;
    QPixmap *m_hover;
    QPixmap *m_press;
};

#endif // __QT_MINEBUTTON_H__
