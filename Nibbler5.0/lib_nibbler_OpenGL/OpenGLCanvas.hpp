//
// OpenGLCanvas.hpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_OpenGL
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 11:29:42 2014 Nathan AUBERT
// Last update Sun Apr  6 11:29:43 2014 Nathan AUBERT
//

#ifndef NIBBLER_OPENGL_CANVAS_HPP_
# define NIBBLER_OPENGL_CANVAS_HPP_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <SFML/Graphics.hpp>

class OpenGLCanvas : public QWidget, public sf::RenderWindow
{
public:
  OpenGLCanvas(QWidget &, const QPoint &, const QSize &, uint);
  virtual ~OpenGLCanvas(void) {};

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

#endif // !NIBBLER_OpenGL_CANVAS_HPP_
