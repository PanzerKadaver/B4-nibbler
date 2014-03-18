//
// Point.hpp for Point.hpp in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 00:26:40 2014 alois
// Last update Tue Mar 18 14:27:55 2014 alois
//

#ifndef POINT_HPP_
# define POINT_HPP_

# include <utility>

class Point
{
public:
  Point(int x, int y);
  ~Point() {}

  char			GetContent() const { return content; }
  std::pair<int,int>	GetCoord() const { return coord; }

  void			SetContent(char c) { content = ic; }
  void			SetCoord(std::pair &c) { coord = c; }

private:
  char			content;
  std::pair<int, int>	coord;
};

#endif
