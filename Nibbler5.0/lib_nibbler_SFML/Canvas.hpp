#ifndef NIBBLER_CANVAS_HPP_
# define NIBBLER_CANVAS_HPP_

#include <QtGui/QWidget>
#include <deque>

#include "Nibbler.hpp"
#include "SFMLCanvas.hpp"

class Canvas : public SFMLCanvas
{
public:

  typedef std::deque<QPoint> SnakeBody;
  typedef std::deque<sf::Sprite> BodySprite;
  typedef char  **land;

  // Ctor
  Canvas(QWidget &, const QPoint &, const QSize &, const QPoint &, const SnakeBody &, const Direction &, const bool &, const land &, uint, uint, uint);
  // Dtor
  ~Canvas(void) {};

  // Fcts
  void    OnInit(void);
  void    OnUpdate();

  void    DrawMap();
  void    DrawFood(const QPoint &);
  void    DrawSnakeHead();
  void    DrawSnakeBody();

private:
  const QPoint    &_head;
  const SnakeBody &_body;
  const Direction &_dir;
  const bool      &_die;
  uint            _width;
  uint            _height;
  uint            _unit;
  const land      &_land;

  sf::Texture     _land_tex;
  sf::Texture     _head_tex;
  sf::Texture     _body_tex;
  sf::Texture     _food_tex;
};

#endif /* !NIBBLER_CANVAS_HPP_ */
