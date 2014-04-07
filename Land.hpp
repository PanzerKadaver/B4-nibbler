//
// Land.hpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:32 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:32 2014 Nathan AUBERT
//

#ifndef NIBLER_LAND_HPP_
# define NIBLER_LAND_HPP_

#include <QtCore/QtCore>

class Land
{
public:
  typedef char  **land;

    Land(uint, uint, uint);
  ~Land();

  char  &getCell(const QPoint &);
  char  &getCell(uint, uint);
  const land  &getMap(void);

  uint  width() const;
  uint  height() const;
  uint  unit() const;

private:
  char  **_land;
  uint  _width;
  uint  _height;
  uint  _unit;
};

#endif /* !NIBLER_LAND_HPP_ */
