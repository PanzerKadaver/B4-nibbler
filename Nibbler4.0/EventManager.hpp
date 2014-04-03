//
// EventManager.hpp for EventManager.hpp in /home/alois/rendu/nibbler/Nibbler4.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Thu Apr  3 19:06:38 2014 alois
// Last update Thu Apr  3 19:06:46 2014 alois
//

#ifndef EVENTMANAGER_HPP_
# define EVENTMANAGER_HPP_

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

  void resetDir();
  void keyAction(Direction, bool);
  bool isOutside();
  bool isEatingHimself();
  void digest();

  bool goTop();
  bool goLeft();
  bool goRight();
  bool goBottom();

  Snake   &_snake;
  Land    &_land;
  GameManager &_engine;
  QTimer  _timer;
  bool    _right;
  bool    _left;
  bool    _top;
  bool    _bottom;
};

#endif /* !EVENTMANAGER_HPP_ */
