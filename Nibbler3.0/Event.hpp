//
// Event.hpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 14:17:06 2014 Nathan AUBERT
// Last update Tue Apr  1 15:44:18 2014 Nathan AUBERT
//

#ifndef NIBBLER_EVENT_HPP_
# define NIBBLER_EVENT_HPP_

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include "GameManager.hpp"

class EventManager : public QWidget, public GameManager
{
public:
EventManager(QWidget *parent, Qt::WindowFlags f = 0);
    ~EventManager() {};

private:
  void    keyPressEvent(QKeyEvent *e);
  void    turnKeyAction(int key);
};

#endif /* !NIBBLER_EVENT_HPP_ */
