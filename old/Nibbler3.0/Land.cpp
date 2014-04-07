//
// Land.cpp for Land in /home/alois/rendu/nibbler/nibbler
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Tue Mar 18 01:11:32 2014 alois
// Last update Tue Apr  1 20:16:16 2014 Nathan AUBERT
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

// caca
void Land::initFood()
{
  std::deque<Point> EmptyList;

  // read all cell
  for (int i = 0; i < this->width; i++)
    {
      for (int j = 0; j < this->height; j++)
	{
	  if (((this->land)[i][j]).GetContent() == ' ')
	    {
	      EmptyList.push_back((this->land)[i][j]);
	    }
	}
    }
  // get rand one
  Point p = Randomizer::GetItem<std::deque<Point> >(EmptyList);
  ((this->land)[p.GetX()][p.GetY()]).SetContent('f');
}

// inversion x y
// void Land::initSnake()
// {
//   int midWidth = this->width / 2;
//   int midHeight = this->height / 2;

//   Point ptmp;
//   ptmp.SetX(midWidth);
//   ptmp.SetY(midHeight);
//   ptmp.SetContent('s');

//   (this->land)[midWidth][midHeight - 1] = ptmp;
//   (this->land)[midWidth][midHeight] = ptmp;
//   (this->land)[midWidth][midHeight + 1] = ptmp;
// }

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
  initFood();
}
