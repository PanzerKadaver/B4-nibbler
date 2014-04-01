#ifndef NIBBLER_EVENT_HPP_
# define NIBBLER_EVENT_HPP_

#include <QtCore\QtCore>
#include <QtGui\QtGui>

class EventManager : public QWidget
{
public:
    EventManager(QWidget *parent, Qt::WindowFlags f = 0);
    ~EventManager() {};

private:
    void    keyPressEvent(QKeyEvent *e);
};

#endif /* !NIBBLER_EVENT_HPP_ */
