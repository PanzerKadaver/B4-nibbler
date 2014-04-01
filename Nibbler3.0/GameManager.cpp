//
// GameManager.cpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 14:42:40 2014 Nathan AUBERT
// Last update Tue Apr  1 14:52:36 2014 Nathan AUBERT
//

#include "GameManager.hpp"

int		change_dir(int dir, char t)
{
  bool isLeft = (t == 'l');

  if (dir == 2 || dir == 3)
    dir = isLeft ? 0 : 1;
  else if (dir == 1)
    dir = isLeft ? 2 : 3;
  else if (dir == 0)
    dir = isLeft ? 3 : 2;
  return dir;
}

void				GameManager::turn_func(char t)
{
  dir = change_dir(dir, t);
  move();
}

int				GameManager::getSnakeX()
{
  return (*snake.begin()).GetX();
    /*std::deque<Point>::iterator	it = snake.begin();

      return (*it).GetX();*/
}

int				GameManager::getSnakeY()
{
  return (*snake.begin()).GetX();
  /*  std::deque<Point>::iterator	it = snake.begin();

      return (*it).GetY();*/
}

void	GameManager::move()
{
  int	x = getSnakeX(), y = getSnakeY();
  Point new_pt(x, y);

  if (dir == 0)
    new_pt.SetX(x - 1);
  else if (dir == 1)
    new_pt.SetX(x + 1);
  else if (dir == 2)
    new_pt.SetY(y - 1);
  else
    new_pt.SetY(y + 1);

  snake.push_front(new_pt);
  snake.pop_back();
}
