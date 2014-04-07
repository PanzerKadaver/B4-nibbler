#ifndef NIBBLER_CANVAS_HPP_
# define NIBBLER_CANVAS_HPP_

#include <QtGui/QWidget>

#include "Nibbler.hpp"
#include "GameManager.hpp"
#include "QtCanvas.hpp"

class Canvas : public QtCanvas
{
public:
  // Ctor
  Canvas(QWidget &parent, const QPoint &pos, const QSize &size, GameManager &engine);
  // Dtor
  ~Canvas(void) {};

  // Fcts
  void    OnInit(void);
  void    OnUpdate(QPainter &painter);

  void    DrawMap(QPainter &painter, Land &land);
  void    DrawFood(QPainter &painter, const QPoint &p, uint s);
  void    DrawSnakeHead(QPainter &painter, const QPoint &pos, Direction dir);
  void    DrawSnakeTongue(QPainter &painter, const QPoint &pos, Direction dir);
  void    DrawSnakeBody(QPainter &painter, const Snake::Body &body);

private:
  GameManager   &_engine;
};

#endif /* !NIBBLER_CANVAS_HPP_ */
