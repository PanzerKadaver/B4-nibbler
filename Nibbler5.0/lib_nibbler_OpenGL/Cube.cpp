#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Cube.hpp"

Cube::Cube(float x, float y, float z, float s, float r, float g, float b) :
  _x(x),
  _y(y),
  _z(z),
  _s(s),
  _r(r),
  _g(g),
  _b(b)
{
  _vertex[0] = Point3D(-1 * s, -1 * s, s);
  _vertex[1] = Point3D(-1 * s,  s, s);
  _vertex[2] = Point3D( s,  s, s);
  _vertex[3] = Point3D( s, -1 * s, s);
  _vertex[4] = Point3D(-1 * s, -1 * s, -1 * s);
  _vertex[5] = Point3D(-1 * s,  s, -1 * s);
  _vertex[6] = Point3D( s,  s, -1 * s);
  _vertex[7] = Point3D( s, -1 * s, -1 * s);
}

void  Cube::draw()
{
  int   f[6][4] = {
    { 0, 1, 2, 3 },
    { 3, 2, 6, 7 },
    { 4, 5, 6, 7 },
    { 0, 1, 5, 4 },
    { 1, 5, 6, 2 },
    { 0, 4, 7, 3 },
  };

  glPushMatrix();
  glTranslatef(_x, _y, _z);

  for (int i = 0; i < 6; i++)
  {
    glBegin(GL_POLYGON);
    for (int j = 0; j < 4; j++)
    {
      glColor3f(_r, _g, _b);
      glVertex3f(_vertex[f[i][j]]._x, _vertex[f[i][j]]._y, _vertex[f[i][j]]._z);
    }
    glEnd();
  }

  glPopMatrix();
}
