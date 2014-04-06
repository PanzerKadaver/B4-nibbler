//
// Canvas.hpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_QPaint
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 11:10:20 2014 Nathan AUBERT
// Last update Sun Apr  6 11:10:21 2014 Nathan AUBERT
//

#ifndef NIBBLER_CANVAS_HPP_
# define NIBBLER_CANVAS_HPP_

#include <QtGui/QWidget>
#include <deque>

#include "Nibbler.hpp"
#include "QtCanvas.hpp"

class Canvas : public QtCanvas
{
public:

  typedef std::deque<QPoint> SnakeBody;
  typedef char  **land;

  // Ctor
  Canvas(QWidget &, const QPoint &, const QSize &, const QPoint &, const SnakeBody &, const Direction &, const bool &, const land &);
  // Dtor
  ~Canvas(void) {};

  // Fcts
  void    OnInit(void);
  void    OnUpdate(QPainter &painter);

  void    DrawMap(QPainter &painter);
  void    DrawFood(QPainter &painter, const QPoint &p);
  void    DrawSnakeHead(QPainter &painter);
  void    DrawSnakeBody(QPainter &painter);

private:
  const QPoint    &_head;
  const SnakeBody &_body;
  const Direction &_dir;
  const bool      &_die;
  uint            _width;
  uint            _height;
  const land      &_land;
};

#endif /* !NIBBLER_CANVAS_HPP_ */
