//
// Land.cpp for Land in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 01:11:32 2014 alois
// Last update Thu Mar 20 14:44:54 2014 alois
//

#include "Land.hpp"

Land::Land(unsigned int size) : width(size), height(size)
{
  init();
}

Land::Land(unsigned int w, unsigned int h) : width(w), height(h)
{
  init();
}

// faut que l on decide si on taf avec des uint ou des int ou des size_t
void Land::addBorder()
{
  Point *border = new Point('b'); // not sure
  for (int j = 0; j < this->height; ++j)
    {
      border.SetY(j);
      border.SetX(0);
      Land[0][j] = border;
      border.SetX(width);
      Land[width][j] = border;
    }
  for (int i = 1; i < this->width - 1; ++i)
    {
      border.SetX(i);
      border.SetY(0);
      Land[i][0] = border;
      border.SetY(height);
      Land[0][height] = border;
    }
}

void Land::init()
{
  Point point();

  for (int i = 0; i < this->width; ++i)
    for (int j = 0; j < this->height; ++j)
      {
	point.SetX = i;
	point.SetY = j;
	Land[i][j] = point;
      }
  addBorder();
}

void Land::update(std::deque<Point>)
{
  /* update std::deque<std::deque<Point> > land with the new snake coords */
}
