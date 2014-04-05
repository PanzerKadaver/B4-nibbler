#ifndef NIBBLER_SFML_CANVAS_HPP_
# define NIBBLER_SFML_CANVAS_HPP_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <SFML/Graphics.hpp>

class SFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
  SFMLCanvas(QWidget &, const QPoint &, const QSize &, uint);
  virtual ~SFMLCanvas(void) {};

protected:
  virtual void  OnInit(void) = 0;
  virtual void  OnUpdate(void) = 0;

  QPaintEngine  *paintEngine() const;
  void          showEvent(QShowEvent *);
  void          paintEvent(QPaintEvent *);

  QTimer  _t;
  bool    _init;
  uint    _fps;
};

#endif // !NIBBLER_SFML_CANVAS_HPP_
