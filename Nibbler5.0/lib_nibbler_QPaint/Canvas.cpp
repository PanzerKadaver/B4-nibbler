#include <iostream>

#include "Canvas.hpp"

typedef char  **land;

Canvas::Canvas(QWidget &parent, const QPoint &pos, const QSize &size, const QPoint &h, const SnakeBody &b, const Direction &d, const bool &die, const land &l) :
  QtCanvas(parent, pos, size, 60),
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
  std::cout << "Canvas init done !" << std::endl;
}

void    Canvas::OnUpdate(QPainter &painter)
{
  DrawMap(painter);
  DrawSnakeBody(painter);
  //DrawSnakeTongue(painter, QPoint(12, 10), RIGHT);
  DrawSnakeHead(painter);
  if (_die)
    _t.stop();
}

void    Canvas::DrawMap(QPainter &painter)
{
  QColor  green(qRgb(28, 120, 0));

  for (uint i = 0; i < _width; i++)
    for (uint j = 0; j < _height; j++)
    {
      painter.setBrush(green);
      painter.drawRect(i * MAP_UNIT, j * MAP_UNIT, MAP_UNIT, MAP_UNIT);
      if (_land[i][j] == 'f')
        DrawFood(painter, QPoint(i, j));
    }
}

void    Canvas::DrawFood(QPainter &painter, const QPoint &p)
{
  QColor  red(qRgb(255, 0, 0));

  painter.setBrush(red);
  painter.drawEllipse(p.x() * MAP_UNIT, p.y() * MAP_UNIT, MAP_UNIT, MAP_UNIT);
}

void    Canvas::DrawSnakeBody(QPainter &painter)
{
  QColor  yellow(qRgb(254, 231, 0));
  uint    i = 0;
  qreal   delta = ((MAP_UNIT * 3) - MAP_UNIT) / ((qreal)_body.size());

  //std::cout << "Delta body : " << delta << std::endl;

  painter.setBrush(yellow);
  while (i < _body.size())
  {
    //qreal     size = ((MAP_UNIT) + (delta * i)) / 2;
    qreal       size = MAP_UNIT;
    QPointF   pos = QPointF(_body[i].x() * MAP_UNIT + MAP_UNIT / 2 , _body[i].y() * MAP_UNIT + MAP_UNIT / 2);
    painter.drawEllipse(pos, size, size);
    //std::cout << "Body[" << i << "] C(" << body[i].x() << "/" << body[i].y() << ") P(" << pos.x() << "/" << pos.y() << ") S(" << size << ")" << std::endl;
    ++i;
  };
  //system("PAUSE");
}

void    Canvas::DrawSnakeTongue(QPainter &painter)
{
  /*painter.setBrush(QBrush(black_yellow));
  painter.drawEllipse(40, 25, MAP_UNIT * 2.5, MAP_UNIT * 2.5);
  painter.setBrush(QBrush(red));
  painter.drawEllipse(70, 40, MAP_UNIT, MAP_UNIT);*/
}

// not sure of the type of pos.x() and pos.y()
static uint calcPos(uint pos, uint u, bool b)
{
  return pos * u + u - (u * b + u / 4);
}

void    Canvas::DrawSnakeHead(QPainter &painter)
{
  QColor	yellow(qRgb(254, 231, 0));
  QColor	black(qRgb(0, 0, 0));
  uint		u = MAP_UNIT;

  painter.setBrush(yellow);
  painter.drawEllipse((_head.x() * u) - u, (_head.y() * u) - u, u * 3, u * 3);
  painter.setBrush(QBrush(black));
  if (_dir == RIGHT || _dir == LEFT)
  {
    uint posX = calcPos(_head.x(), u, _dir == LEFT);
    painter.drawEllipse(posX, calcPos(_head.y(), u, 1), u / 2, u / 2);
    painter.drawEllipse(posX, calcPos(_head.y(), u, 0), u / 2, u / 2);
  }
  else if (_dir == BOTTOM || _dir == TOP)
  {
    uint posY = calcPos(_head.y(), u, _dir == TOP);
    painter.drawEllipse(calcPos(_head.x(), u, 1), posY, u / 2, u / 2);
    painter.drawEllipse(calcPos(_head.x(), u, 0), posY, u / 2, u / 2);
  }
}
