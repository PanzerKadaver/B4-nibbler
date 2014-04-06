//
// EventManager.hpp for EventManager.hpp in /home/alois/rendu/nibbler/Nibbler4.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Thu Apr  3 19:06:38 2014 alois
// Last update Sun Apr  6 19:38:43 2014 Nathan AUBERT
//

#ifndef NIBBLER_EVENTMANAGER_HPP_
# define NIBBLER_EVENTMANAGER_HPP_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtCore/QTimer>

#include "GameManager.hpp"

class EventManager : public QWidget
{
  Q_OBJECT

public:
  EventManager(QWidget &parent, GameManager &engine, float speed);
  ~EventManager(void);

  typedef bool	(EventManager::*func)(QPoint &);
  struct	op_tab
  {
    Direction	d;
    func	ptr;
  };

  bool goTop(QPoint &);
  bool goLeft(QPoint &);
  bool goRight(QPoint &);
  bool goBottom(QPoint &);

  typedef void	(EventManager::*dFunc)();
  struct	key_tab
  {
    Qt::Key	key;
    dFunc	ptr;
  };

  void	keyTopAction();
  void	keyBotAction();
  void	keyLeftAction();
  void	keyRightAction();
  void	keyLeftDirAction();
  void	keyRightDirAction();
  void	keyEscapeAction();

  void  start();

public slots:
  bool    moveSnake(void);

private:
  Snake   &_snake;
  Land    &_land;
  GameManager &_engine;
  QTimer  _timer;
  bool    _right;
  bool    _left;
  bool    _top;
  bool    _bottom;
  float   _speed;

protected:
  void    keyPressEvent(QKeyEvent *e);
  bool    checkNext(const QPoint &, const QPoint &, const QPoint &, const QPoint &);

  void resetDir();
  void keyAction(Direction, bool);
  bool isOutside(const QPoint &);
  bool isEatingHimself(const QPoint &, const QPoint &);
  bool digest();
};

#endif // !NIBBLER_EVENTMANAGER_HPP_
