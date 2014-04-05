//
// QtCanvas.cpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:51 2014 Nathan AUBERT
// Last update Sat Apr  5 21:08:15 2014 Nathan AUBERT
//

#include <iostream>

#include "include/QtCanvas.hpp"

QtCanvas::QtCanvas(QWidget &parent, const QPoint &pos, const QSize &size, uint frameRate) :
    QWidget(&parent),
    _init(false),
    _fps(frameRate)
{
    QWidget::move(pos);
    QWidget::resize(size);
}

void    QtCanvas::showEvent(QShowEvent *)
{
    //std::cout << "Show event" << std::endl;
    if (!_init)
    {
        //std::cout << "Show event init" << std::endl;
        OnInit();

        connect(&_t, SIGNAL(timeout()), this, SLOT(repaint()));
        _t.start((1 / _fps) * 1000);
        _init = true;
    }
}

void    QtCanvas::paintEvent(QPaintEvent *)
{
    QPainter    painter(this);

    OnUpdate(painter);
}
