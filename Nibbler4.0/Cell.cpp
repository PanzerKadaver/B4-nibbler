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
