#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>

#include "TexCube.hpp"

TexCube::TexCube(float x, float y, float z, float s, uint tex_id) :
  _x(x),
  _y(y),
  _z(z),
  _s(s)
{
  _vertex.push_back(Point3D(-1 * s, -1 * s, s));
  _vertex.push_back(Point3D(-1 * s, s, s));
  _vertex.push_back(Point3D(s, s, s));
  _vertex.push_back(Point3D(s, -1 * s, s));
  _vertex.push_back(Point3D(-1 * s, -1 * s, -1 * s));
  _vertex.push_back(Point3D(-1 * s, s, -1 * s));  
  _vertex.push_back(Point3D(s, s, -1 * s));  
  _vertex.push_back(Point3D(s, -1 * s, -1 * s));

  _tex.push_back(QPointF(0.0f, 0.0f));
  _tex.push_back(QPointF(0.0f, 1.0f));
  _tex.push_back(QPointF(1.0f, 0.0f));
  _tex.push_back(QPointF(1.0f, 1.0f));
}

void  TexCube::draw()
{
  int   f[6][4] = {
    { 0, 1, 2, 3 },
    { 3, 2, 6, 7 },
    { 4, 5, 6, 7 },
    { 0, 1, 5, 4 },
    { 1, 5, 6, 2 },
    { 0, 4, 7, 3 }
  };
  int   t[6][4] = {
    { 0, 1, 3, 2 },
    { 0, 1, 3, 2 },
    { 2, 3, 1, 0 },
    { 2, 3, 1, 0 },
    { 0, 1, 3, 2 },
    { 2, 3, 1, 0 }
  };

  glPushMatrix();
  glTranslatef(_x, _y, _z);
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glBindTexture(GL_TEXTURE_2D, _id);
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

  for (int i = 0; i < 6; i++)
  {
    glBegin(GL_QUADS);
    for (int j = 0; j < 4; j++)
    {
      glTexCoord2f(_tex[t[i][j]].x(), _tex[t[i][j]].y());
      glVertex3f(_vertex[f[i][j]]._x, _vertex[f[i][j]]._y, _vertex[f[i][j]]._z);
    }
    glEnd();
  }
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}
