//
// Land.hpp for Land in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 01:03:10 2014 alois
// Last update Tue Mar 18 01:04:44 2014 alois
//

#ifndef LAND_HPP_
# define LAND_HPP_

# include <deque>
# include "Point.hpp"

class Land
{
public:
  Land();
  ~Land();

private:
  std::deque<std::deque<Point> > land;
};

#endif
