//
// Land.cpp for Land in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 01:11:32 2014 alois
// Last update Thu Mar 20 22:10:44 2014 alois
//

//
#include <iostream>
//
#include "Land.hpp"

Land::Land(int size) : width(size), height(size)
{
  init();
}

Land::Land(int w, int h) : width(w), height(h)
{
  init();
}

// faut que l on decide si on taf avec des uint ou des int ou des size_t

void Land::init()
{
  Point point;

  for (int i = 0; i < this->width; ++i)
    {
      std::deque<Point> tmp;
      for (int j = 0; j < this->height; ++j)
	{
	  point.SetContent((i == 0 || j == 0 || i + 1 == this->width || j + 1 == this->height)
			   ? 'b' : ' ');
	  point.SetX(i);
	  point.SetY(j);
	  tmp.push_back(point);
	}
      this->land.push_back(tmp);
      tmp.erase(tmp.begin(), tmp.end());
    }
}

/*
void Land::update(std::deque<Point>)
{
  // update std::deque<std::deque<Point> > land with the new snake coords
}
*/
