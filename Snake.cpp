//
// Snake.cpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:59 2014 Nathan AUBERT
// Last update Thu Apr  3 21:33:00 2014 Nathan AUBERT
//

#include <iostream>

#include "Snake.hpp"

Snake::Snake(const QPoint &startPos, uint startLength, Land &ref) :
  _pos(startPos),
  _dir(RIGHT),
  _die(false),
  _land(ref)
{
  uint   i = 0;

  _land.getCell(_pos) = 's';
  while (i < startLength)
  {
    _body.push_front(QPoint(startPos.x() - (i + 1), startPos.y()));
    _land.getCell(QPoint(startPos.x() - (i + 1), startPos.y())) = 's';
    ++i;
  }
  std::cout << "Bob says hello !" << std::endl;
}

const QPoint  &Snake::getPos(void) const
{
  return _pos;
}
const Direction     &Snake::getDir(void) const
{
  return _dir;
}
const Snake::Body   &Snake::getBody(void) const
{
  return _body;
}
const bool    &Snake::isDie(void) const
{
  return _die;
}

void    Snake::setPos(const QPoint &dest)
{
  _pos.setX(dest.x());
  _pos.setY(dest.y());
}
void    Snake::setDir(Direction dir)
{
  _dir = dir;
}

void    Snake::addBody(void)
{
  _body.push_front(QPoint(_pos.x(), _pos.y()));
}

void    Snake::move(const QPoint &dest)
{
  int  i = _body.size() - 1;
  QPoint  old;
  QPoint  t;

  _land.getCell(_body[i].x(), _body[i].y()) = 0;
  old = _body[i];
  _body[i].setX(_pos.x());
  _body[i].setY(_pos.y());
  _land.getCell(_body[i].x(), _body[i].y()) = 's';
  setPos(dest);
  _land.getCell(_pos.x(), _pos.y()) = 's';
  --i;
  while (i >= 0)
  {
    _land.getCell(_body[i].x(), _body[i].y()) = 0;
    t = old;
    old = _body[i];
    _body[i] = t;
    _land.getCell(_body[i].x(), _body[i].y()) = 's';
    --i;
  }
}

void    Snake::die(void)
{
  _die = true;
  std::cout << "Bob is dead" << std::endl;
}
