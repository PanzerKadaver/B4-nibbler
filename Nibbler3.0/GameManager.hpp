//
// GameManager.hpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 14:44:47 2014 Nathan AUBERT
// Last update Tue Apr  1 15:33:13 2014 Nathan AUBERT
//

#ifndef GAME_MANAGER_HPP_
# define GAME_MANAGER_HPP_

# include <deque>
# include <iostream>
# include "Point.hpp"

class GameManager
{
public:
  GameManager() {}
  ~GameManager() {}

  void	move();
  void	turn_func(char);
  int	getSnakeX();
  int	getSnakeY();

  std::deque<Point>	snake;
  int			dir; // 0 == LEFT, 1 == RIGHT, 2 == UP, 3 == DOWN
};

int	change_dir(int, char);

#endif /* GAME_MANAGER_HPP_ */
