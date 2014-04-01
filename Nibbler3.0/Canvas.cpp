#include <iostream>

#include "Canvas.hpp"
#include "Nibbler.hpp"

Canvas::Canvas(QWidget &parent, const QPoint &pos, const QSize &size) :
  QtCanvas(parent, pos, size, 60)
{

}

void    Canvas::OnInit()
{
  std::cout << "Init !" << std::endl;
  _map = new QRect**[MAP_SIZE];
  for (int i = 0; i < MAP_SIZE; i++)
    {
      _map[i] = new QRect*[MAP_SIZE];
      for (int j = 0; j < MAP_SIZE; j++)
        {
	  _map[i][j] = new QRect(i * MAP_UNIT, j * MAP_UNIT, MAP_UNIT, MAP_UNIT);
        }
    }
}

void    Canvas::OnUpdate(QPainter &painter)
{
  QColor  red(qRgb(255, 0, 0));
  QColor  green(qRgb(28, 120, 0));    
  QColor  black_yellow(qRgb(197, 180, 0));
    

  painter.setBrush(QBrush(green));
  for (int i = 0; i < MAP_SIZE; i++)
    {
      for (int j = 0; j < MAP_SIZE; j++)
        {
	  painter.drawRect(*(_map[i][j]));
        }
    }
  /*painter.setBrush(QBrush(black_yellow));
    painter.drawEllipse(40, 25, MAP_UNIT * 2.5, MAP_UNIT * 2.5);
    painter.setBrush(QBrush(red));
    painter.drawEllipse(70, 40, MAP_UNIT, MAP_UNIT);*/
  DrawSnakeHead(painter, QPoint(3, 3));
    
    
}

void    Canvas::DrawSnakeHead(QPainter &painter, const QPoint &pos)
{
  QColor  yellow(qRgb(254, 231, 0));
  QColor  black(qRgb(0, 0, 0));

  painter.setBrush(yellow);
  painter.drawEllipse((pos.x() * MAP_UNIT) - (MAP_UNIT * 2), (pos.y() * MAP_UNIT) - (MAP_UNIT * 2), (MAP_UNIT * 3), (MAP_UNIT * 3));
  painter.setBrush(QBrush(black));
  painter.drawEllipse((pos.x() * MAP_UNIT) - (MAP_UNIT / 4), (pos.y() * MAP_UNIT) - MAP_UNIT - (MAP_UNIT / 4), (MAP_UNIT / 2), (MAP_UNIT / 2));
  painter.drawEllipse((pos.x() * MAP_UNIT) - (MAP_UNIT / 4), (pos.y() * MAP_UNIT) - (MAP_UNIT / 4), (MAP_UNIT / 2), (MAP_UNIT / 2));
}
