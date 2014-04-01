//
// Event.cpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 13:54:22 2014 Nathan AUBERT
// Last update Tue Apr  1 15:49:44 2014 Nathan AUBERT
//

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
  if (e->key() == 16777234 || e->key() == 16777236)
    turnKeyAction(e->key());
  else
    {
      //    optionKeyAction(e->key());
    }

 //  if (e->key() == 16777234)
 //    {
 //      std::cout << "LEFT" << std::endl;      
 //    }
 // else if (e->key() == 16777236)
 //   {
 //      std::cout << "RIGHT" << std::endl;           
 //   }
 // else if (e->key() == 16777216)
 //   {
 //      std::cout << "QUIT" << std::endl;           
 //   }
  std::cout << "key == " << e->key() << std::endl;
}

void	EventManager::turnKeyAction(int key)
{
  if (key == 16777234)
    GameManager::turn_func('l');
  else
    GameManager::turn_func('r');
}
