//
// EventManager.cpp for EventManager.cpp in /home/alois/rendu/nibbler/Nibbler4.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Thu Apr  3 19:06:20 2014 alois
// Last update Thu Apr  3 19:06:21 2014 alois
//

#include <iostream>
#include <QtGui/QApplication>

#include "Event.hpp"

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
  if (!_snake.isDie())
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

bool EventManager::isOutside()
{
  if (next_s.x() >= _land.width() || next_s.x() < 0 || next_s.y() >= _land.height() || next_s.y() < 0)
    {
      _snake.die();
      _timer.stop();
      return false;
    }
  return true;
}

bool EventManager::isEatingHimself()
{
  for (int i = 0; i < _snake.getBody().size(); ++i)
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
  if (!isOutside() || !isEatingHimself())
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

bool EventManager::goTop()
{
    next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() - 1);
    next_f = QPoint(next_m.x() - 1, next_m.y() - 1);
    next_s = QPoint(next_m.x(), next_m.y() - 1);
    next_t = QPoint(next_m.x() + 1,  next_m.y() - 1);

    return checkNext(next_m, next_f, next_s, next_t);
}
bool EventManager::goLeft()
{
    QPoint next_m = QPoint(_snake.getPos().x() - 1, _snake.getPos().y());
    QPoint next_f = QPoint(next_m.x() - 1, _snake.getPos().y() - 1);
    QPoint next_s = QPoint(next_m.x() - 1, _snake.getPos().y());
    QPoint next_t = QPoint(next_m.x() - 1, _snake.getPos().y() + 1);

    return checkNext(next_m, next_f, next_s, next_t);
}
bool EventManager::goRight()
{
    QPoint next_m = QPoint(_snake.getPos().x() + 1, _snake.getPos().y());
    QPoint next_f = QPoint(next_m.x() + 1, _snake.getPos().y() - 1);
    QPoint next_s = QPoint(next_m.x() + 1, _snake.getPos().y());
    QPoint next_t = QPoint(next_m.x() + 1, _snake.getPos().y() + 1);

    return checkNext(next_m, next_f, next_s, next_t);
}
bool EventManager::goBottom()
{
    QPoint next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() + 1);
    QPoint next_f = QPoint(next_m.x() - 1, next_m.y() + 1);
    QPoint next_s = QPoint(next_m.x(), next_m.y() + 1);
    QPoint next_t = QPoint(next_m.x() + 1, next_m.y() + 1);

    return checkNext(next_m, next_f, next_s, next_t);
}

bool    EventManager::moveSnake(void)
{
  bool canGoNext;

  if (_snake.getDir() == TOP)
    canGoNext = goTop();
  else if (_snake.getDir() == LEFT)
    canGoNext = goLeft();
  else if (_snake.getDir() == RIGHT)
    canGoNext = goRight();
  else
    canGoNext = goBottom();

  if (canGoNext)
    {
      _snake.move(next_m);
      return true;
    }
  return false;
}
