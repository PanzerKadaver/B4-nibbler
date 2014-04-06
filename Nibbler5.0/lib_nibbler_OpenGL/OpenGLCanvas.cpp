//
// OpenGLCanvas.cpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_OpenGL
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 11:29:35 2014 Nathan AUBERT
// Last update Sun Apr  6 11:44:22 2014 Nathan AUBERT
//

#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>

#include "OpenGLCanvas.hpp"

#ifdef Q_WS_X11
#include <QtGui/QX11Info>
#include <X11/Xlib.h>
#endif

OpenGLCanvas::OpenGLCanvas(QWidget &parent, const QPoint &pos, const QSize &size, uint framerate) :
  QWidget(&parent),
  _init(false),
  _fps(framerate)
{
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);
  setAttribute(Qt::WA_DeleteOnClose);

  QWidget::move(pos);
  QWidget::resize(size);
}

QPaintEngine  *OpenGLCanvas::paintEngine() const
{
  return 0;
}

void          OpenGLCanvas::showEvent(QShowEvent *)
{
  if (!_init)
  {
#ifdef Q_WS_X11
    XFlush(QX11Info::display());
#endif

    sf::RenderWindow::create(winId());
    OnInit();
    connect(&_t, SIGNAL(timeout()), this, SLOT(repaint()));
    _t.start((1 / _fps) * 1000);
    _init = true;
  }
}

void          OpenGLCanvas::paintEvent(QPaintEvent *)
{
  OnUpdate();
  display();
}
