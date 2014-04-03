#include <iostream>
#include <cstdlib>
#include <ctime>

#include "GameManager.hpp"

GameManager::GameManager(uint width, uint height, uint unit) :
  _score(0)
{
  _land = new Land(width, height, unit);
  //_snake = new Snake(QPoint(5, 5), 4, this->getLand());
  _snake = new Snake(QPoint(width / 2, height / 2), 4, this->getLand());
  srand(time(NULL));
}
GameManager::~GameManager(void)
{
  delete _snake;
  delete _land;
}

Land    &GameManager::getLand()
{
  return *_land;
}

Snake   &GameManager::getSnake()
{
  return *_snake;
}

uint    GameManager::score() const
{
  return _score;
}

bool    GameManager::checkAround(uint x, uint y) const
{
  uint  t_x = (x > 0) ? (x - 1) : (x);
  uint  t_y = (y > 0) ? (y - 1) : (y);
  uint  b_x = (x < _land->width() - 1) ? (x + 1) : (x);
  uint  b_y = (y < _land->height() - 1) ? (y + 1) : (y);
  uint  i = t_x;
  uint  j;

  while (i < b_x)
  {
    j = t_y;
    while (j < b_y)
    {
      if (i != x && j != y)
      {
        if (_land->getCell(i, j).getContent() == 's')
          return false;
      }
      ++j;
    }
    ++i;
  }
  return true;
}

void    GameManager::printMap()
{
  char  c;

  std::cout << "===========================" << std::endl;
  for (int i = 0; i < _land->width(); i++)
  {
    for (int j = 0; j < _land->height(); j++)
    {
      if ((c = _land->getCell(j, i).getContent()) == 0)
        std::cout << ".";
      else
        std::cout << c;
    }
    std::cout << std::endl;
  }
  std::cout << "===========================" << std::endl;
}

bool    GameManager::popFood()
{
  std::vector<QPoint> empty;
  uint                random;

  //printMap();
  for (int i = 0; i < _land->width(); i++)
    for (int j = 0; j < _land->height(); j++)
      if (_land->getCell(j, i).getContent() == 0)
        if (checkAround(j, i))
          empty.push_back(QPoint(j, i));
  std::cout << "Free cells : " << empty.size() << std::endl;
  if (empty.size() == 0)
    return false;
  random = rand() % empty.size();
  std::cout << "Rand : " << random << std::endl;
  std::cout << "New apple in [" << empty[random].x() << "][" << empty[random].y() << "]" << std::endl;
  _land->getCell(empty[random]).setContent('f');
  return true;
}
