#ifndef NIBBLER_EVENT_HPP_
# define NIBBLER_EVENT_HPP_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtCore/QTimer>

#include "GameManager.hpp"

class EventManager : public QWidget
{
  Q_OBJECT

public:
  EventManager(QWidget &parent, GameManager &engine, uint speed);
  ~EventManager(void) {};

  public slots:
    bool    moveSnake(void);

private:
  void    keyPressEvent(QKeyEvent *e);
  bool    checkNext(const QPoint &, const QPoint &, const QPoint &, const QPoint &);

  Snake   &_snake;
  Land    &_land;
  GameManager &_engine;
  QTimer  _timer;
  bool    _right;
  bool    _left;
  bool    _top;
  bool    _bottom;
};

#endif /* !NIBBLER_EVENT_HPP_ */
