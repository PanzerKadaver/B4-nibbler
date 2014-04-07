//
// EventManager.hpp for EventManager.hpp in /home/alois/rendu/nibbler/Nibbler4.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Thu Apr  3 19:06:38 2014 alois
// Last update Fri Apr  4 17:43:18 2014 Nathan AUBERT
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

protected:
  void    keyPressEvent(QKeyEvent *e);
  bool    checkNext(const QPoint &, const QPoint &, const QPoint &, const QPoint &);

  void resetDir();
  void keyAction(Direction, bool);
  bool isOutside(const QPoint &);
  bool isEatingHimself(const QPoint &, const QPoint &);
  void digest();
};

#endif /* !EVENTMANAGER_HPP_ */
