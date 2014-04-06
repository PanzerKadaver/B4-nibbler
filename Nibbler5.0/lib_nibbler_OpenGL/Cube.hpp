#ifndef NIBBLER_CUBE_HPP_
# define NIBBLER_CUBE_HPP_

#include <QtGui/QtGui>
#include <array>

#include "Point3D.hpp"

class Cube
{
public:
  Cube(float, float, float, float, float, float, float);
  ~Cube(void) {};

  void  draw();

private:
  float   _x;
  float   _y;
  float   _z;
  float   _s;
  float   _r;
  float   _g;
  float   _b;
  std::array<Point3D, 8> _vertex;
};

#endif // !NIBBLER_CUBE_HPP_
