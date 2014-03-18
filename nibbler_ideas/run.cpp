#include "Land.hpp"
#include "Point.hpp"
#include "Traductor.hpp"
#include "run.hpp"

#include <unistd.h> // DEBUG

int		change_dir(int dir, char t)
{
  /* change dir value due to 't' */
}

void		GameManager::turn_func(char t)
{
  /* check head position */
  /* create a new point with his new coords, depending of 't' (left or right) */
  /* pushfront of snake and popback the last */

  dir = change_dir(dir, t);
}

void		GameManager::move()
{
  /* check head position */
  /* create a new point with his new coords, depending of GameManager.dir */
  /* pushfront of snake and popback the last */
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
      update(); // modify the std::deque<std::deque<Point> > land;
      /* for_each land draw(); */
      usleep(250000); // DEBUG
    }

  return 0;
}
