//
// Coord.hpp for Coord in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 00:37:41 2014 alois
// Last update Tue Mar 18 00:58:38 2014 alois
//

#ifndef COORD_HPP_
#define COORD_HPP_

#include <utility>

/* should we remove this and use a simple pair ? */

class Coord
{
public:
  Coord(int i, int j) : x(i), y(j) {}
  ~Coord() {};

  int getX() const { return x; }
  int gety() const { return y; }

private:
  int	x;
  int	y;
};

#endif
