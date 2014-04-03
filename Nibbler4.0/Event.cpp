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
  _bottom = true;
  _right = true;
  _left = false;
  _top = true;
}

void    EventManager::keyPressEvent(QKeyEvent *e)
{
  e->accept();
  if (e->key() == Qt::Key_Z && _top && !_snake.isDie())
  {
    _snake.setDir(TOP);
    _bottom = false;
    _right = true;
    _left = true;
    _top = true;
    if (moveSnake())
      _timer.start();
    else
      _timer.stop();
  }
  else if (e->key() == Qt::Key_Q && _left && !_snake.isDie())
  {
    _snake.setDir(LEFT);
    _bottom = true;
    _right = false;
    _left = true;
    _top = true;
    if (moveSnake())
      _timer.start();
    else
      _timer.stop();
  }
  else if (e->key() == Qt::Key_D && _right && !_snake.isDie())
  {
    _snake.setDir(RIGHT);
    _bottom = true;
    _right = true;
    _left = false;
    _top = true;
    if (moveSnake())
      _timer.start();
    else
      _timer.stop();
  }
  else if (e->key() == Qt::Key_S && _bottom && !_snake.isDie())
  {
    _snake.setDir(BOTTOM);
    _bottom = true;
    _right = true;
    _left = true;
    _top = false;
    if (moveSnake())
      _timer.start();
    else
      _timer.stop();
  }
}

bool  EventManager::checkNext(const QPoint &next_m, const QPoint &next_f, const QPoint &next_s, const QPoint &next_t)
{
  int i = 0;

  if (next_s.x() >= _land.width() || next_s.x() < 0 || next_s.y() >= _land.height() || next_s.y() < 0)
  {
    _snake.die();
    _timer.stop();
    return false;
  }
  while (i < _snake.getBody().size())
  {
    if (_snake.getBody()[i] == next_s || _snake.getBody()[i] == next_m)
    {
      _snake.die();
      _timer.stop();
      return false;
    }
    ++i;
  }
  if (_land.getCell(next_f).getContent() == 'f')
  {    
    _land.getCell(next_f).setContent(0);
    _engine.popFood();
    _snake.addBody();
  }
  else if (_land.getCell(next_s).getContent() == 'f')
  {    
    _land.getCell(next_s).setContent(0);
    _engine.popFood();
    _snake.addBody();
  }
  else if (_land.getCell(next_t).getContent() == 'f')
  {    
    _land.getCell(next_t).setContent(0);
    _engine.popFood();
    _snake.addBody();
  }
  return true;
}

bool    EventManager::moveSnake(void)
{
  QPoint  next_m;
  QPoint  next_f;
  QPoint  next_s;
  QPoint  next_t;

  if (_snake.getDir() == TOP)
  {
    next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() - 1);
    next_f = QPoint(next_m.x() - 1, next_m.y() - 1);
    next_s = QPoint(next_m.x(), next_m.y() - 1);
    next_t = QPoint(next_m.x() + 1,  next_m.y() - 1);
  }
  else if (_snake.getDir() == LEFT)
  {
    next_m = QPoint(_snake.getPos().x() - 1, _snake.getPos().y());
    next_f = QPoint(next_m.x() - 1, _snake.getPos().y() - 1);
    next_s = QPoint(next_m.x() - 1, _snake.getPos().y());
    next_t = QPoint(next_m.x() - 1, _snake.getPos().y() + 1);
  }
  else if (_snake.getDir() == RIGHT)
  {
    next_m = QPoint(_snake.getPos().x() + 1, _snake.getPos().y());
    next_f = QPoint(next_m.x() + 1, _snake.getPos().y() - 1);
    next_s = QPoint(next_m.x() + 1, _snake.getPos().y());
    next_t = QPoint(next_m.x() + 1, _snake.getPos().y() + 1);
  }
  else
  {
    next_m = QPoint(_snake.getPos().x(), _snake.getPos().y() + 1);
    next_f = QPoint(next_m.x() - 1, next_m.y() + 1);
    next_s = QPoint(next_m.x(), next_m.y() + 1);
    next_t = QPoint(next_m.x() + 1, next_m.y() + 1);
  }

  if (checkNext(next_m, next_f, next_s, next_t))
    _snake.move(next_m);
  else
    return false;
  return true;
}
