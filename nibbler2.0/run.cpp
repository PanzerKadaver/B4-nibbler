#include "Land.hpp"
#include "Point.hpp"
#include "Traductor.hpp"
#include "run.hpp"

#include <unistd.h> // DEBUG
int		change_dir(int dir, char t)
{
  bool isLeft = (t == 'l');

  if (dir == 2 || dir == 3)
    dir = isLeft ? 0 : 1;
  else if (dir == 1)
    dir = isLeft ? 2 : 3;
  else if (dir == 0)
    dir = isLeft ? 3 : 2;

/*
  if (dir == 2 || dir == 3)
    dir = !isLeft;
  else if (dir == 1)
    dir = 3 - isLeft;
  else if (dir == 0)
    dir = 2 + isLeft;
*/
}


void				GameManager::turn_func(char t)
{
  dir = change_dir(dir, t);
  move();
}

int				GameManager::getSnakeX()
{
  std::deque<Point>::iterator	it = snake.begin();

  return (*it).GetX();
}

int				GameManager::getSnakeY()
{
  std::deque<Point>::iterator	it = snake.begin();

  return (*it).GetY();
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

int		GameManager::run()
{
  bool		state = true;

  /* create land and init it */

  while (state)
    {
      /*
	event loop, if left pressed : move_func('l');
	if right pressed : move_func('r');
	if ESC pressed : state = false
      */
      move(); // stay on the same dir
      /* update land */
      /* for_each land draw(); */
      usleep(250000); // DEBUG
    }

  return 0;
}
