//
// GameManager.cpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
//
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
//
// Started on  Tue Apr  1 14:42:40 2014 Nathan AUBERT
// Last update Tue Apr  1 19:22:49 2014 alois
//

#include "GameManager.hpp"

GameManager::GameManager() : score(0), dir(1), isStarve(true), country(24, 24)
{
  Land Ocalrissian(24,24);
  this->country = Ocalrissian;
  initSnake();
  initFood();
}

void GameManager::initFood()
{
  std::deque<Point> EmptyList;

  // read all cell
  for (int i = 0; i < this->country.width; i++)
      for (int j = 0; j < this->country.height; j++)
	  if (((this->country.land)[i][j]).GetContent() == ' ')
	      EmptyList.push_back((this->country.land)[i][j]);
  // get rand one
  Point p = Randomizer::GetItem<std::deque<Point> >(EmptyList);
  ((this->country.land)[p.GetX()][p.GetY()]).SetContent('f');
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

void GameManager::printSnake()
{
  for(int i = 0; i < this->snake; ++i)
    {
      Point tmp = this->snake[i];
      (this->country.land)[tmp.GetX()][tmp.GetY()] = tmp.GetContent();
    }
}

// possible inversion x y
void GameManager::initSnake()
{
  int midWidth = this->country.width / 2;
  int midHeight = this->country.height / 2;

  Point ptmp;
  ptmp.SetX(midWidth);
  ptmp.SetContent('s');

  for (int i = 0; i < 3; ++i)
    {
      ptmp.SetY(midHeight - (i - 1)); // 3 / 2 ?
      this->snake.push_back(ptmp);
    }
  /*
  (this->country)[midWidth][midHeight - 1] = ptmp;
  (this->country)[midWidth][midHeight] = ptmp;
  (this->country)[midWidth][midHeight + 1] = ptmp;
  */
}

void	GameManager::Eat()
{
  this->score++;
  this->isStarve = false;
  initFood();
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

  std::cout << x << " " << y << std::endl;

  if (dir == 0)
    nextPoint.SetX(x - 1);
  else if (dir == 1)
    nextPoint.SetX(x + 1);
  else if (dir == 2)
    nextPoint.SetY(y - 1);
  else
    nextPoint.SetY(y + 1);

  int npx = nextPoint.GetX();
  int npy = nextPoint.GetY();

  std::deque<std::deque<Point> > deq = this->country.GetLand();

  nextPoint.SetContent((deq[npx][npy]).GetContent());

  if (CheckNext(nextPoint))
    {
      snake.push_front(nextPoint);
      if (isStarve)
	snake.pop_back();
      isStarve = true;
      printSnake();
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

GameManager::Land & GameManager::Land::operator=(const GameManager::Land &l)
{
  this->width =l.GetWidth();
  this->height =l.GetHeight();
  this->land =l.GetLand();
  return (*this);
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
}
