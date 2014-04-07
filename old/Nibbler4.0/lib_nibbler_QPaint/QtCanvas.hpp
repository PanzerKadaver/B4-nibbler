//
// QtCanvas.hpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:55 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:55 2014 Nathan AUBERT
//

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

    // Attr
    QTimer  _t;
    bool    _init;
    uint    _fps;
};

#endif /* !NIBBLER_QT_CANVAS_HPP_ */
