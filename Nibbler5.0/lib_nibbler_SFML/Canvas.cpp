#include <iostream>

#include "Canvas.hpp"

typedef char  **land;

Canvas::Canvas(QWidget &parent, const QPoint &pos, const QSize &size, const QPoint &h, const SnakeBody &b, const Direction &d, const bool &die, const land &l, uint width, uint height, uint unit) :
  SFMLCanvas(parent, pos, size, 60),
  _head(h),
  _body(b),
  _dir(d),
  _die(die),
  _land(l),
  _width(width),
  _height(height),
  _unit(unit)
{
  if (unit != 32)
  {
    std::cerr << "Draw unit must be 32px" << std::endl;
    exit(-1);
  }
  else if (width < 15 || height < 15)
  {
    std::cerr << "Map is too little" << std::endl;
    exit(-1);
  }
}

void    Canvas::OnInit()
{
  _land_tex.loadFromFile("asset/land.png");
  _land_tex.setRepeated(true);
  _head_tex.loadFromFile("asset/head.png");
  _body_tex.loadFromFile("asset/body.png");
  _food_tex.loadFromFile("asset/food.png");
  std::cout << "Canvas init done !" << std::endl;
}

void    Canvas::OnUpdate()
{
  DrawMap();
  DrawSnakeBody();
  DrawSnakeHead();
  if (_die)
    _t.stop();
}

void    Canvas::DrawMap()
{
  sf::Sprite  _land_s;

  _land_s.setTexture(_land_tex);
  _land_s.setTextureRect(sf::IntRect(0, 0, _width * _unit, _height * _unit));

  draw(_land_s);

  for (uint i = 0; i < _width; i++)
    for (uint j = 0; j < _height; j++)
      if (_land[i][j] == 'f')
        DrawFood(QPoint(i, j));
}

void    Canvas::DrawFood(const QPoint &p)
{
  sf::Sprite _food_s;

  _food_s.setTexture(_food_tex);
  _food_s.setPosition(p.x() * _unit, p.y() * _unit);

  draw(_food_s);
}

void    Canvas::DrawSnakeBody()
{
  uint    i = 0;

  while (i < _body.size())
  {
    sf::Sprite  _body_s;
    qreal     size = _unit;
    QPoint  pos((_body[i].x() * _unit) - _unit / 2, (_body[i].y() * _unit) - _unit / 2);

    _body_s.setTexture(_body_tex);
    _body_s.setPosition(pos.x(), pos.y());

    draw(_body_s);

    ++i;
  };

}

void    Canvas::DrawSnakeHead()
{
  QPoint  pos((_head.x() * _unit) + _unit / 2, (_head.y() * _unit) + _unit / 2);
  sf::Sprite  _head_s;

  _head_s.setTexture(_head_tex);
  _head_s.setPosition(pos.x(), pos.y());
  _head_s.setOrigin((_unit * 3) / 2, (_unit * 3) / 2);
  _head_s.setRotation(90 * _dir);

  draw(_head_s);
}
