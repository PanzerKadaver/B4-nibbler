#include "Land.hpp"
#include "Point.hpp"
#include "Traductor.hpp"
#include "run.hpp"

#include <unistd.h> // DEBUG

int		change_dir(int dir, char t)
{
  if ((dir == 0 && t == 'l') || (dir == 1 && t == 'r'))
    dir = 3;
  else if ((dir == 0 && t == 'r') || (dir == 1 && t == 'l'))
    dir = 2;
  else if ((dir == 2 && t == 'l') || (dir == 3 && t == 'l'))
    dir = 0;
  else if ((dir == 2 && t == 'r') || (dir == 3 && t == 'r'))
    dir = 1;
}

void				GameManager::turn_func(char t)
{
  /*std::deque<Point>::iterator	head = snake.begin();
  int				x = getSnakeX(), y = getSnakeY();*/

  dir = change_dir(dir, t);
  move();
  /*if (dir == 0)
    Point new_pt(x - 1, y);
  else if (dir == 1)
    Point new_pt(x + 1, y);
  else if (dir == 2)
    Point new_pt(x, y - 1);
  else
    Point new_pt(x, y + 1);

  snake.push_front(new_pt);
  snake.pop_back();*/
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

void				GameManager::move()
{
  std::deque<Point>::iterator	head = snake.begin();
  int				x = getSnakeX(), y = getSnakeY();

  if (dir == 0)
    Point new_pt(x - 1, y);
  else if (dir == 1)
    Point new_pt(x + 1, y);
  else if (dir == 2)
    Point new_pt(x, y - 1);
  else
    Point new_pt(x, y + 1);

  snake.push_front(new_pt);
  snake.pop_back();
}

int		run()
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
