//
// Canvas.cpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_OpenGL
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 11:06:55 2014 Nathan AUBERT
// Last update Sun Apr  6 11:07:38 2014 Nathan AUBERT
//

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Canvas.hpp"
#include "Cube.hpp"

typedef char  **land;

Canvas::Canvas(QWidget &parent, const QPoint &pos, const QSize &size, const QPoint &h, const SnakeBody &b, const Direction &d, const bool &die, const land &l) :
  OpenGLCanvas(parent, pos, size, 60),
  _head(h),
  _body(b),
  _dir(d),
  _die(die),
  _land(l)
{
  _width = size.width() / MAP_UNIT;
  _height = size.height() / MAP_UNIT;
}

void    Canvas::OnInit()
{
  glMatrixMode(GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,(double)_width/_height,1,1000);
  glEnable(GL_DEPTH_TEST);

  if (!_grass.loadFromFile("asset/grass_texture.bmp") ||
    !_apple.loadFromFile("asset/apple_texture.bmp") ||
    !_snake.loadFromFile("asset/snake_texture.bmp"))
  {
    std::cerr << "Error while loading textures" << std::endl;
    exit(EXIT_FAILURE);
  }

  _grass_id = 0;
  {
    glGenTextures(1, &_grass_id);
    glBindTexture(GL_TEXTURE_2D, _grass_id);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, 256, 256, GL_RGBA, GL_UNSIGNED_BYTE, _grass.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  }
  _apple_id = 0;
  {
    glGenTextures(1, &_apple_id);
    glBindTexture(GL_TEXTURE_2D, _apple_id);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, 256, 256, GL_RGBA, GL_UNSIGNED_BYTE, _apple.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  }
  _snake_id = 0;
  {
    glGenTextures(1, &_snake_id);
    glBindTexture(GL_TEXTURE_2D, _snake_id);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, 256, 256, GL_RGBA, GL_UNSIGNED_BYTE, _snake.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  }

  std::cout << "Canvas init done !" << std::endl;
}

void    Canvas::OnUpdate()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5,5,5,0,0,0,0,1,0);

  DrawMap();
  DrawSnakeBody();
  DrawSnakeHead();
  if (_die)
    _t.stop();
}

void    Canvas::DrawMap()
{
  for (uint i = 0; i < _width; i++)
    for (uint j = 0; j < _height; j++)
    {
      Cube c(-1 * (i * 0.5f), -5.0f, -1 * (j * 0.5f), 0.25f, 0.f, 1.f, 0.f);

      c.draw();
      if (_land[i][j] == 'f')
        DrawFood(QPoint(i, j));
    }
}

void    Canvas::DrawFood(const QPoint &p)
{
  Cube c(-1 * (p.x() * 0.5f), -4.0f, -1 * (p.y() * 0.5f), 0.25f, 1.f, 0.f, 0.f);

  c.draw();
}

void    Canvas::DrawSnakeBody()
{
  uint    i = 0;

  while (i < _body.size())
  {
    QPoint pos (_body[i].x() * 0.5f, _body[i].y() * 0.5f);

    Cube c(-1.f * pos.x(), -4.0f, -1.f * pos.y(), 0.5f, 1.f, 1.f, 0.f);

    c.draw();
    ++i;
  };

}

void    Canvas::DrawSnakeHead()
{
  QPoint	pos((_head.x() * 0.5f) + 0.5f / 2, (_head.y() * 0.5f) + 0.5f / 2);

  Cube    c(-1.f * pos.x(), -4.0f,  -1.f * pos.y(), 0.75f, 1.f, 1.f, 0.f);

  c.draw();
}
