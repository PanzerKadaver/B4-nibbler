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

int     run(int ac, char **av, int width, int height, const std::string &path)
{
  typedef char  **land;
  typedef std::deque<QPoint> SnakeBody;
  typedef void    *Canvas;
  typedef Canvas  (*new_func)(QWidget &, const QPoint &, const QSize &, const QPoint &, const SnakeBody &, const Direction &, const bool &, const land &);
  typedef void    (*utils_func)(Canvas);

  QApplication    app(ac, av);
  QFrame          *mainFrame = new QFrame;
  GameManager     engine(width, height, MAP_UNIT);
  EventManager    *events  = new EventManager(*mainFrame, engine, 0.75);
  void            *libHandler;
  Canvas          myCanvas;
  new_func        newCanvas;
  utils_func      showCanvas;
  utils_func      deleteCanvas;

  QDesktopWidget widget;
  QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());

  if (MAP_UNIT < 5 || MAP_UNIT > 50)
  {
    std::cerr << "Map unit must be between 5 and 50px" << std::endl;
    return (-1);
  }
  if (width < 15 || width > 100)
  {
    std::cerr << "Map width must be between 15 and 100 units" << std::endl;
    return -1;
  }
  if (height < 15 || height > 100)
  {
    std::cerr << "Map height must be between 15 and 100 units" << std::endl;
    return -1;
  }
  if (width * MAP_UNIT > mainScreenSize.width() || height * MAP_UNIT > mainScreenSize.height())
  {
    std::cerr << "Map resolution " << width * MAP_UNIT << "x" << height * MAP_UNIT << ", exceed your screen resolution " << mainScreenSize.width() << "x" << mainScreenSize.height() << std::endl;
    return -1;
  }

  if (!(libHandler = Library::open(path.c_str())))
  {
    std::cerr << Library::error() << std::endl;
    return (-1);
  }
  else
    std::cout << "Lib sucessfully loaded" << std::endl;

  if (!(newCanvas = reinterpret_cast<new_func>(Library::sym(libHandler, "newCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    return (-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  if (!(showCanvas = reinterpret_cast<utils_func>(Library::sym(libHandler, "showCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    return (-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  if (!(deleteCanvas = reinterpret_cast<utils_func>(Library::sym(libHandler, "deleteCanvas"))))
  {
    std::cerr << Library::error() << std::endl;
    return (-1);
  }
  else
    std::cout << "Function loaded" << std::endl;

  myCanvas = newCanvas(*mainFrame, QPoint(0, 0), QSize(width * MAP_UNIT + 1, height * MAP_UNIT + 1), engine.getSnake().getPos(), engine.getSnake().getBody(), engine.getSnake().getDir(), engine.getSnake().isDie(), engine.getLand().getMap());

  mainFrame->setWindowTitle("Nibbler");
  mainFrame->resize(QSize(width * MAP_UNIT + 1, height * MAP_UNIT + 1));
  //mainFrame->move(0, 0);
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

int   main(int ac, char **av)
{
  if (ac != 4)
  {
    std::cerr << "Usage : ./nibbler width height libpath" << std::endl;
    return (-1);
  }

  run(ac, av, atoi(av[1]), atoi(av[2]), std::string(av[3]));
  return 0;
}
