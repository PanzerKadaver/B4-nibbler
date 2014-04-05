#ifndef NIBLER_GAMEMANAGER_HPP_
# define NIBLER_GAMEMANAGER_HPP_

#include "Land.hpp"
#include "Snake.hpp"

class GameManager
{
public:
  GameManager(uint, uint, uint);
  ~GameManager(void);

  Land    &getLand();
  Snake   &getSnake();
  uint    score() const;

  bool  checkAround(uint, uint) const;
  bool  popFood();
  void  addScore(uint);
  void  printMap();

private:
  Snake   *_snake;
  Land    *_land;
  uint    _score;
  QPoint  _old;
};

#endif /* !NIBLER_GAMEMANAGER_HPP_ */
