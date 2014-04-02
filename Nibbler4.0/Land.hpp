#ifndef NIBLER_LAND_HPP_
# define NIBLER_LAND_HPP_

#include "Cell.hpp"

class Land
{
public:
  Land(uint, uint, uint);
  ~Land();

  Cell  &getCell(const QPoint &);
  Cell  &getCell(uint, uint);

  uint  width() const;
  uint  height() const;
  uint  unit() const;

private:
  Cell  ***_land;
  uint  _width;
  uint  _height;
  uint  _unit;
};

#endif /* !NIBLER_LAND_HPP_ */
