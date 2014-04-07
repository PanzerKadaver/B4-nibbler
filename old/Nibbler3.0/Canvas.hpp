#ifndef NIBBLER_CANVAS_HPP_
# define NIBBLER_CANVAS_HPP_

#include <QtGui/QWidget>

#include "QtCanvas.hpp"

class Canvas : public QtCanvas
{
public:
    // Ctor
    Canvas(QWidget &parent, const QPoint &pos, const QSize &size);
    // Dtor
    ~Canvas(void) {};

    // Fcts
    void    OnInit(void);
    void    OnUpdate(QPainter &painter);

    void    DrawSnakeHead(QPainter &painter, const QPoint &pos);

private:
    // Attr
    QRect   ***_map;
};

#endif /* !NIBBLER_CANVAS_HPP_ */
