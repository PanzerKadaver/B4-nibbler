//
// Land.hpp for Land in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 01:03:10 2014 alois
// Last update Thu Mar 20 20:23:11 2014 alois
//

#ifndef LAND_HPP_
# define LAND_HPP_

# include <deque>
# include "Point.hpp"

class Land
{
public:
  Land(int);
  Land(int, int);
  ~Land() {}

  int					GetWidth() const { return width; }
  int					GetHeight() const { return height; }
  std::deque<std::deque<Point> >	GetLand() const { return land; }

private	:
  //void	addBorder();
  void	init();
  //void	update(std::deque<Point>);

  int					width;
  int					height;
  std::deque<std::deque<Point> >	land;
};

#endif
