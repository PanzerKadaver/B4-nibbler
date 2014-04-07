//
// GameManager.hpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 12:20:51 2014 Nathan AUBERT
// Last update Sun Apr  6 19:33:31 2014 Nathan AUBERT
//

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
  QPoint  _old;
};

#endif /* !NIBLER_GAMEMANAGER_HPP_ */
