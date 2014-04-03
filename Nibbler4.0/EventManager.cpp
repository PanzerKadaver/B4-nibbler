//
// EventManager.cpp for EventManager.cpp in /home/alois/rendu/nibbler/Nibbler4.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Thu Apr  3 19:06:20 2014 alois
// Last update Thu Apr  3 21:04:44 2014 Nathan AUBERT
//

#include <iostream>
#include <QtGui/QApplication>

#include "EventManager.hpp"

EventManager::EventManager(QWidget &parent, GameManager &engine, uint speed) :
  QWidget(&parent, 0),
  _snake(engine.getSnake()),
  _land(engine.getLand()),
  _engine(engine)
{
  setFocusPolicy(Qt::StrongFocus);
  //connect(&_timer, SIGNAL(timeout()), this, SLOT(moveSnake()));
  //_timer.start(800 / speed);
  resetDir();
  _left = false;
}

void EventManager::resetDir()
{
  _bottom = true;
  _right = true;
  _left = true;
  _top = true;
}

void EventManager::keyAction(Direction eDir, bool isDir)
{
  _snake.setDir(eDir);
  resetDir();
  isDir = false;
  if (moveSnake())
    _timer.start();
  else
    _timer.stop();
}

void    EventManager::keyPressEvent(QKeyEvent *e)
{
  e->accept();
  if (_snake.isDie())
    return;

  if (e->key() == Qt::Key_Z && _top)
    keyAction(TOP, &_bottom);
  else if (e->key() == Qt::Key_Q && _left)
    keyAction(LEFT, &_right);
  else if (e->key() == Qt::Key_D && _right)
    keyAction(RIGHT, &_left);
  else if (e->key() == Qt::Key_S && _bottom)
    keyAction(BOTTOM, &_top);
}

bool EventManager::isOutside(const QPoint &next_s)
{
  if (next_s.x() >= _land.width() || next_s.x() < 0 || next_s.y() >= _land.height() || next_s.y() < 0)
    {
      _snake.die();
      _timer.stop();
      return false;
    }
  return true;
}

bool EventManager::isEatingHimself(const QPoint &next_s, const QPoint &next_m)
{
  for (uint i = 0; i < _snake.getBody().size(); ++i)
    if (_snake.getBody()[i] == next_s || _snake.getBody()[i] == next_m)
      {
	_snake.die();
	_timer.stop();
	return false;
      }
  return true;
}

void EventManager::digest()
{
  _engine.popFood();
  _snake.addBody();
}

bool  EventManager::checkNext(const QPoint &next_m, const QPoint &next_f, const QPoint &next_s, const QPoint &next_t)
{
  if (!isOutside(next_s) || !isEatingHimself(next_s, next_m))
    return false;
  if (_land.getCell(next_f).getContent() == 'f')
    {
      _land.getCell(next_f).setContent(0);
      digest();
    }
  else if (_land.getCell(next_s).getContent() == 'f')
    {
      _land.getCell(next_s).setContent(0);
      digest();
    }
  else if (_land.getCell(next_t).getContent() == 'f')
    {
      _land.getCell(next_t).setContent(0);
      digest();
    }
  return true;
}

bool EventManager::goTop(QPoint &next_m)
{
  next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() - 1);
  QPoint next_f = QPoint(next_m.x() - 1, next_m.y() - 1);
  QPoint next_s = QPoint(next_m.x(), next_m.y() - 1);
  QPoint next_t = QPoint(next_m.x() + 1,  next_m.y() - 1);

  return checkNext(next_m, next_f, next_s, next_t);
}

bool EventManager::goLeft(QPoint &next_m)
{
  next_m = QPoint(_snake.getPos().x() - 1, _snake.getPos().y());
  QPoint next_f = QPoint(next_m.x() - 1, _snake.getPos().y() - 1);
  QPoint next_s = QPoint(next_m.x() - 1, _snake.getPos().y());
  QPoint next_t = QPoint(next_m.x() - 1, _snake.getPos().y() + 1);

  return checkNext(next_m, next_f, next_s, next_t);
}

bool EventManager::goRight(QPoint &next_m)
{
  next_m = QPoint(_snake.getPos().x() + 1, _snake.getPos().y());
  QPoint next_f = QPoint(next_m.x() + 1, _snake.getPos().y() - 1);
  QPoint next_s = QPoint(next_m.x() + 1, _snake.getPos().y());
  QPoint next_t = QPoint(next_m.x() + 1, _snake.getPos().y() + 1);

  return checkNext(next_m, next_f, next_s, next_t);
}

bool EventManager::goBottom(QPoint &next_m)
{
  next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() + 1);
  QPoint next_f = QPoint(next_m.x() - 1, next_m.y() + 1);
  QPoint next_s = QPoint(next_m.x(), next_m.y() + 1);
  QPoint next_t = QPoint(next_m.x() + 1, next_m.y() + 1);

  return checkNext(next_m, next_f, next_s, next_t);
}

EventManager::op_tab	go_function[] = {
  { TOP, &EventManager::goTop },
  { LEFT, &EventManager::goLeft },
  { RIGHT, &EventManager::goRight },
  { BOTTOM, &EventManager::goBottom }
};

bool		EventManager::moveSnake(void)
{
  bool		canGoNext = false;
  QPoint	next_m;
  Direction	currentDir = _snake.getDir();
  int		i = 0;

  while (i < 4)
    {
      if (currentDir == go_function[i].d)
	{
	  canGoNext = (this->*go_function[i].ptr)(next_m);
	  break;
	}
      ++i;
    }
  if (canGoNext)
    {
      _snake.move(next_m);
      return true;
    }
  return false;
}
