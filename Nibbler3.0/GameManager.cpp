//
// GameManager.cpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 14:42:40 2014 Nathan AUBERT
// Last update Tue Apr  1 18:14:22 2014 alois
//

#include "GameManager.hpp"

GameManager::GameManager() : score(0), dir(1), isStarve(true)
{
  Land Ocalrissian(24,24);
  this->country = Ocalrissian;
  //  this->snake(); // init deque -> initSnake()
}

int	GameManager::ChangeDir(int dir, char t)
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

void	GameManager::Eat()
{
  this->score++;
  this->isStarve = false;
}

bool	GameManager::CheckNext(Point next)
{
  if (next.GetContent() == 's' || next.GetContent() == 'b')
    return false;
  if (next.GetContent() == 'f')
    Eat();
  return true;
}

void	GameManager::turn_func(char t)
{
  dir = ChangeDir(dir, t);
  move();
}

int	GameManager::getSnakeX()
{
  return (*snake.begin()).GetX();
  /*std::deque<Point>::iterator	it = snake.begin();
    return (*it).GetX();*/
}

int	GameManager::getSnakeY()
{
  return (*snake.begin()).GetY();
  /*  std::deque<Point>::iterator	it = snake.begin();
      return (*it).GetY();*/
}

void	GameManager::move()
{
  int	x = getSnakeX(), y = getSnakeY();
  Point nextPoint(x, y);

  if (dir == 0)
    nextPoint.SetX(x - 1);
  else if (dir == 1)
    nextPoint.SetX(x + 1);
  else if (dir == 2)
    nextPoint.SetY(y - 1);
  else
    nextPoint.SetY(y + 1);

  nextPoint.SetContent(((this->country.land)[nextPoint.GetX()][nextPoint.GetY()]).GetContent());

  if (CheckNext(nextPoint))
    {
      snake.push_front(nextPoint);
      if (isStarve)
	snake.pop_back();
      isStarve++; // http://programmers.stackexchange.com/q/230928/121841
    }
  else
    {
      // We have to stop the game
    }
}

GameManager::Land::Land(int size) : width(size), height(size)
{
  init();
}

GameManager::Land::Land(int w, int h) : width(w), height(h)
{
  init();
}

GameManager::Land::Land(const GameManager::Land &l)
  : width(l.GetWidth()), height(l.GetHeight()), land(l.GetLand())
{
}

GameManager::Land & GameManager::operator=(const GameManager::Land &l)
  : width(l.GetWidth()), height(l.GetHeight()), land(l.GetLand())
{
}


void GameManager::Land::initFood()
{
  std::deque<Point> EmptyList;

  // read all cell
  for (int i = 0; i < this->width; i++)
      for (int j = 0; j < this->height; j++)
	  if (((this->land)[i][j]).GetContent() == ' ')
	      EmptyList.push_back((this->land)[i][j]);
  // get rand one
  Point p = Randomizer::GetItem<std::deque<Point> >(EmptyList);
  ((this->land)[p.GetX()][p.GetY()]).SetContent('f');
}

// possible inversion x y
void GameManager::Land::initSnake()
{
  int midWidth = this->width / 2;
  int midHeight = this->height / 2;

  Point ptmp;
  ptmp.SetX(midWidth);
  ptmp.SetY(midHeight);
  ptmp.SetContent('s');

  (this->land)[midWidth][midHeight - 1] = ptmp;
  (this->land)[midWidth][midHeight] = ptmp;
  (this->land)[midWidth][midHeight + 1] = ptmp;
}

void GameManager::Land::init()
{
  Point point;

  for (int i = 0; i < this->width; ++i)
    {
      std::deque<Point> tmp;
      for (int j = 0; j < this->height; ++j)
	{
	  point.SetContent((i == 0 || j == 0 || i + 1 == this->width || j + 1 == this->height)
			   ? 'b' : ' ');
	  point.SetX(i);
	  point.SetY(j);
	  tmp.push_back(point);
	}
      this->land.push_back(tmp);
      tmp.erase(tmp.begin(), tmp.end());
    }
  initSnake();
  initFood();
}
