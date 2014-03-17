//
// Point.hpp for Point.hpp in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 00:26:40 2014 alois
// Last update Tue Mar 18 00:32:53 2014 alois
//

#ifndef POINT_HPP_
# define POINT_HPP_

class Point
{
public:
  Point() {}
  ~Point() {}

  IContent	GetContent() const { return content; }
  Coord		GetCoord() const { return coord; }

  void		SetContent(const IContent &ic) { content = ic; }
  void		SetCoord(const Coord &c) { coord = c; }

private:
  IContent	content;
  Coord		coord;
};

#endif
