#ifndef NIBBLER_POINT3D_HPP_
# define NIBBLER_POINT3D_HPP_

class Point3D
{
public:
  Point3D(void) {};
  Point3D(float x, float y, float z) : _x(x), _y(y), _z(z) {};
  ~Point3D(void) {};
  float _x;
  float _y;
  float _z;
};

#endif // !NIBBLER_POINT3D_HPP_
