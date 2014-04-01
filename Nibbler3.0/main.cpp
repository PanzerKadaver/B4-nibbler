//
// main.cpp for  in /home/aubert_n/rep/nibbler/Nibbler3.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 13:46:23 2014 Nathan AUBERT
// Last update Tue Apr  1 17:17:13 2014 Nathan AUBERT
//

#include <QtGui/QApplication>
#include <QtGui/QFrame>

#include "Nibbler.hpp"
#include "Canvas.hpp"
#include "Event.hpp"

int     main(int ac, char **av)
{
  QApplication    app(ac, av);
  QFrame          *mainFrame = new QFrame;
  GameManager	  snakeObj;
  EventManager    events(mainFrame);
  Canvas          myCanvas(*mainFrame, QPoint(0, 0), QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1));

  mainFrame->setWindowTitle("Nibbler");
  mainFrame->resize(QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1));
  mainFrame->show();

  events.show();
  myCanvas.show();

  app.exec();
  return (0);
}
