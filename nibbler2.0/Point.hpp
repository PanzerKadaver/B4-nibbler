//
// Point.hpp for Point.hpp in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 00:26:40 2014 alois
// Last update Thu Mar 20 17:14:04 2014 alois
//

#ifndef POINT_HPP_
# define POINT_HPP_

# include <iosfwd>
# include <utility>

class Point
{
public:
  Point() {}
  Point(char c) : content(c) {}
  Point(std::pair<int, int> p) : content(' ') { coord = p; }
  Point(int x, int y) { coord.first = x; coord.second = y; }
  ~Point() {}

  char			GetContent() const { return content; }
  std::pair<int,int>	GetCoord() const { return coord; }
  int			GetX() const { return coord.first; }
  int			GetY() const { return coord.second; }

  void			SetContent(char c) { content = c; }
  void			SetCoord(std::pair<int, int> &pair) { coord = pair; }
  void			SetX(int x) { coord.first = x; }
  void			SetY(int y) { coord.second = y; }

private:
  char			content;
  std::pair<int, int>	coord;
};

std::ostream &operator<<(std::ostream &, const Point &);

#endif
