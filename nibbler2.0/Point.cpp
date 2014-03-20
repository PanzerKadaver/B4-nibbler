//
// Point.cpp for Point in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 14:27:34 2014 alois
// Last update Thu Mar 20 19:36:11 2014 alois
//

#include "Point.hpp"

Point & Point::operator=(const Point &p)
{
  this->content = p.GetContent();
  this->coord = p.GetCoord();
  return *this;
}

std::ostream &operator<<(std::ostream &o, const Point &pt)
{
  o << pt.GetContent();
  return o;
}
