//
// Point.hpp for Point.hpp in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 00:26:40 2014 alois
// Last update Thu Mar 20 22:14:10 2014 alois
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
  Point(std::pair<int, int> p) : content(' ') { coor = p; }
  Point(int x, int y) { coor.first = x; coor.second = y; }
  Point(const Point &p) : content(p.GetContent()), coor(p.GetCoor()) {}
  Point &operator=(const Point&);
  ~Point() {}

  char			GetContent() const { return content; }
  std::pair<int,int>	GetCoor() const { return coor; }
  int			GetX() const { return coor.first; }
  int			GetY() const { return coor.second; }

  void			SetContent(char c) { content = c; }
  void			SetCoor(std::pair<int, int> &pair) { coor = pair; }
  void			SetX(int x) { coor.first = x; }
  void			SetY(int y) { coor.second = y; }

private:
  char			content;
  std::pair<int, int>	coor;
};

std::ostream &operator<<(std::ostream &, const Point &);

#endif
