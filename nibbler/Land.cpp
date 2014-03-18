//
// Land.cpp for Land in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 01:11:32 2014 alois
// Last update Tue Mar 18 01:31:03 2014 alois
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

void Land::addBorder()
{
  Point border; // wants Point need border;
  for (unsigned int j = 0; j < this->height; ++j)
    {
      Land[0][j] = border;
      Land[width][j] = border;
    }
  for (unsigned int i = 1; i < this->width - 1; ++i)
    {
      Land[i][0] = border;
      Land[0][height] = border;
    }
}

void Land::init()
{
  for (size_t i = 0; i < this->width; ++i)
    {
      for (size_t j = 0; j < this->height; ++j)
	{
	  Point point(i, j); // ??
	  Land[i][j] = point;
	}
    }
}

