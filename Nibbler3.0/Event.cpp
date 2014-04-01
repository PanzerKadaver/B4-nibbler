#include <iostream>

#include "Event.hpp"

EventManager::EventManager(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent, f)
{
    setFocusPolicy(Qt::StrongFocus);
}

void    EventManager::keyPressEvent(QKeyEvent *e)
{
    e->accept();
    std::cout << "key == " << e->key() << std::endl;
}
