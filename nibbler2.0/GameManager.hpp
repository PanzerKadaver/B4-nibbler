#ifndef RUN_HPP_
# define RUN_HPP_

# include <deque>
# include "Point.hpp"


class GameManager
{
public:
  GameManager() {}
  ~GameManager() {}

  void	move();
  void	turn_func(char);
  void	draw();
  int	run();
  int	getSnakeX();
  int	getSnakeY();

  std::deque<Point>	snake;
  int			dir; // 0 == LEFT, 1 == RIGHT, 2 == UP, 3 == DOWN
};

int	change_dir(int, char);

#endif /* RUN_HPP_ */
