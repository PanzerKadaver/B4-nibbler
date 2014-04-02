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

private:
  Snake   *_snake;
  Land    *_land;
  uint    _score;
};

#endif /* !NIBLER_GAMEMANAGER_HPP_ */
