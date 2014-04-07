#include <iostream>

#include "QtCanvas.hpp"

QtCanvas::QtCanvas(QWidget &parent, const QPoint &pos, const QSize &size, uint frameRate) :
    QWidget(&parent),
    _init(false),
    _fps(frameRate)
{
    QWidget::move(pos);
    QWidget::resize(size);
}

void    QtCanvas::showEvent(QShowEvent *e)
{
    std::cout << "Show event" << std::endl;
    if (!_init)
    {
        std::cout << "Show event init" << std::endl;
        OnInit();

        connect(&_t, SIGNAL(timeout()), this, SLOT(repaint()));
        _t.start((1 / _fps) * 1000);
        _init = true;
    }
}

void    QtCanvas::paintEvent(QPaintEvent *e)
{
    QPainter    painter(this);

    OnUpdate(painter);
}
