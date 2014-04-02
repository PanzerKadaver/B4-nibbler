#include <iostream>

#include "Snake.hpp"

Snake::Snake(const QPoint &startPos, uint startLength, Land &ref) :
  _pos(startPos),
  _dir(RIGHT),
  _die(false),
  _land(ref)
{
  uint   i = 0;

  _land.getCell(_pos).setContent('s');
  while (i < startLength)
  {
    _body.push_front(QPoint(startPos.x() - (i + 1), startPos.y()));
    _land.getCell(QPoint(startPos.x() - (i + 1), startPos.y())).setContent('s');
    ++i;
  }
  std::cout << "Bob says hello !" << std::endl;
}

const QPoint  &Snake::getPos(void) const
{
  return _pos;
}
Direction     Snake::getDir(void) const
{
  return _dir;
}
const Snake::Body   &Snake::getBody(void) const
{
  return _body;
}
bool    Snake::isDie(void) const
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
  uint   i = 0;

  while (i < _body.size() - 1)
  {
    _land.getCell(_body[i]).setContent(0);
    _body[i].setX(_body[i + 1].x());
    _body[i].setY(_body[i + 1].y());
    _land.getCell(_body[i]).setContent('s');
    ++i;
  }
  _land.getCell(_body[_body.size() - 1]).setContent(0);
  _body[_body.size() - 1].setX(_pos.x());
  _body[_body.size() - 1].setY(_pos.y());
  _land.getCell(_body[_body.size() - 1]).setContent('s');
  _land.getCell(_pos).setContent(0);
  setPos(dest);
  _land.getCell(_pos).setContent('s');
}

void    Snake::die(void)
{
  _die = true;
  std::cout << "Bob is dead" << std::endl;
}
