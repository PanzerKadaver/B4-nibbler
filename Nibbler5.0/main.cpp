//
// main.cpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:36 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:36 2014 Nathan AUBERT
//

#include <QtGui/QApplication>
#include <QtGui/QFrame>

#include "Nibbler.hpp"
#include "EventManager.hpp"
#include "GameManager.hpp"
#include "Library.hpp"

int     main(int ac, char **av)
{
  typedef char  **land;
  typedef std::deque<QPoint> SnakeBody;
  typedef void    *Canvas;
  typedef Canvas  (*new_func)(QWidget &, const QPoint &, const QSize &, const QPoint &, const SnakeBody &, const Direction &, const bool &, const land &, uint, uint, uint);
  typedef void    (*utils_func)(Canvas);

  QApplication    app(ac, av);
  QFrame          *mainFrame = new QFrame;
  GameManager     engine(MAP_SIZE, MAP_SIZE, MAP_UNIT);
  EventManager    *events  = new EventManager(*mainFrame, engine, 0.75);
  void            *libHandler;
  Canvas          myCanvas;
  new_func        newCanvas;
  utils_func      showCanvas;
  utils_func      deleteCanvas;

  if (!(libHandler = Library::open("./lib_nibbler_SFML.dll")))
  {
    std::cerr << Library::error() << std::endl;
    exit(-1);
  }
  else
    std::cout << "Lib sucessfully loaded" << std::endl;

  if (!(newCanvas = reinterpret_cast<new_func>(Library::sym(libHandler, "newCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    exit(-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  if (!(showCanvas = reinterpret_cast<utils_func>(Library::sym(libHandler, "showCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    exit(-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  if (!(deleteCanvas = reinterpret_cast<utils_func>(Library::sym(libHandler, "deleteCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    exit(-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  myCanvas = newCanvas(*mainFrame, QPoint(0, 0), QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1), engine.getSnake().getPos(), engine.getSnake().getBody(), engine.getSnake().getDir(), engine.getSnake().isDie(), engine.getLand().getMap(), MAP_SIZE, MAP_SIZE, MAP_UNIT);

  mainFrame->setWindowTitle("Nibbler");
  mainFrame->resize(QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1));
  mainFrame->show();

  showCanvas(myCanvas);
  events->show();

  events->start();
  app.exec();

  deleteCanvas(myCanvas);
  delete events;
  delete mainFrame;
  if (!Library::close(libHandler))
    std::cout << "Library unloaded" << std::endl;
  else
  {
    std::cerr << Library::error() << std::endl;
    abort();
  }
  return (0);
}
