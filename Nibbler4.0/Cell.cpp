//
// Cell.cpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:09 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:10 2014 Nathan AUBERT
//

#include "Cell.hpp"

Cell::Cell(const QPoint &point) :
  _coord(QPoint(point.x(), point.y())),
  _content(0)
{
}

Cell::Cell(uint x, uint y) :
  _coord(QPoint(x, y)),
  _content(0)
{
}

char    Cell::getContent(void) const
{
  return _content;
}

void    Cell::setContent(char c)
{
  _content = c;
}
