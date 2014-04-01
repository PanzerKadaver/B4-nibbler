#ifndef NIBBLER_QT_CANVAS_HPP_
# define NIBBLER_QT_CANVAS_HPP_

#include <QtGui/QWidget>
#include <QtGui/QGraphicsScene>
#include <QtCore/QTimer>
#include <QtGui/QPainter>

class QtCanvas : public QWidget
{
public:
    // Ctor
    QtCanvas(QWidget &parent, const QPoint &pos, const QSize &size, uint frameRate);
    // Dtor
    ~QtCanvas(void) {};

protected:
    // Contracts
    virtual void OnInit(void) = 0;
    virtual void OnUpdate(QPainter &painter) = 0;

    // Fcts
    void            showEvent(QShowEvent *e);
    void            paintEvent(QPaintEvent *e);

private:
    // Attr
    QTimer  _t;
    bool    _init;
    uint    _fps;
};

#endif /* !NIBBLER_QT_CANVAS_HPP_ */
