//
// Land.cpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:28 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:28 2014 Nathan AUBERT
//

#include <iostream>

#include "Land.hpp"

Land::Land(uint w, uint h, uint u) :
  _width(w),
  _height(h),
  _unit(u)
{
  _land = new char*[w];
  for (uint i = 0; i < w; ++i)
  {
    _land[i] = new char[h];
    for (uint j = 0; j < h; ++j)
      _land[i][j] = 0;
  }
  std::cout << "Land init" << std::endl;
}

Land::~Land()
{
  for (uint i = 0; i < _width; i++)
  {
    delete _land[i];
  }
  delete _land;
}

char  &Land::getCell(const QPoint &p)
{
  return (_land[p.x()][p.y()]);
}

char  &Land::getCell(uint x, uint y)
{
  return (_land[x][y]);
}

uint    Land::width() const
{
  return _width;
}
uint    Land::height() const
{
  return _height;
}
uint    Land::unit() const
{
  return _unit;
}

const Land::land  &Land::getMap()
{
  return _land;
}
