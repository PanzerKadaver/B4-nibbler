//
// Point.cpp for Point in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 14:27:34 2014 alois
// Last update Tue Mar 18 15:54:06 2014 alois
//

#include "Point.hpp"

ostream &operator<<(ostream &o, const Point &pt)
{
  o << pt.GetContent();
  return o;
}
