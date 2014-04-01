//
// GameManager.hpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 14:44:47 2014 Nathan AUBERT
// Last update Tue Apr  1 17:35:58 2014 alois
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <deque>
# include <iostream>
# include "Randomizer.hpp"
# include "Point.hpp"

class GameManager
{
public:
  GameManager();
  ~GameManager() {}

  void	move();
  void	turn_func(char);
  int	getSnakeX();
  int	getSnakeY();

  int score;
  std::deque<Point>	snake;
  int dir; // 0 == LEFT, 1 == RIGHT, 2 == UP, 3 == DOWN
  bool isStarve;

  class Land
  {
  public:
    Land(int);
    Land(int, int);
    ~Land() {}

    int	GetWidth() const { return width; }
    int	GetHeight() const { return height; }
    std::deque<std::deque<Point> >	GetLand() const { return land; }

  private:
    void	init();
    void	initSnake();
    void	initFood();

    int	width;
    int	height;
    std::deque<std::deque<Point> >	land;
  };
};

int	change_dir(int, char);

#endif /* GAMEMANAGER_HPP_ */
