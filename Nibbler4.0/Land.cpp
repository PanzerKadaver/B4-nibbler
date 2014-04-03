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
  _land = new Cell**[w];
  for (uint i = 0; i < w; ++i)
  {
    _land[i] = new Cell*[h];
    for (uint j = 0; j < h; ++j)
      _land[i][j] = new Cell(i, j);
  }
  std::cout << "Land init" << std::endl;
}

Land::~Land()
{
  for (uint i = 0; i < _width; i++)
  {
    for (uint j = 0; j < _height; j++)
      delete  _land[i][j];
    delete _land[i];
  }
  delete _land;
}

Cell  &Land::getCell(const QPoint &p)
{
  /*if (p.x() > _width || p.y() > _height)
  exception;*/
  return *(_land[p.x()][p.y()]);
}

Cell  &Land::getCell(uint x, uint y)
{
  /*if (x > _width || y > _height)
  exception;*/
  return *(_land[x][y]);
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
