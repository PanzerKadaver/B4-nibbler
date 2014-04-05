#include "SFMLCanvas.hpp"

SFMLCanvas::SFMLCanvas(QWidget &parent, const QPoint &pos, const QSize &size, uint framerate) :
  QWidget(&parent),
  _init(false),
  _fps(framerate)
{
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);

  QWidget::move(pos);
  QWidget::resize(size);
}

QPaintEngine  *SFMLCanvas::paintEngine() const
{
  return 0;
}

void          SFMLCanvas::showEvent(QShowEvent *)
{
  if (!_init)
  {
    sf::RenderWindow::create(winId());
    OnInit();
    connect(&_t, SIGNAL(timeout()), this, SLOT(repaint()));
    _t.start((1 / _fps) * 1000);
    _init = true;
  }
}

void          SFMLCanvas::paintEvent(QPaintEvent *)
{
  OnUpdate();
}
