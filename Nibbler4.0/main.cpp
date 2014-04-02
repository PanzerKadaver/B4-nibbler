#include <QtGui/QApplication>
#include <QtGui/QFrame>

#include "Nibbler.hpp"
#include "Canvas.hpp"
#include "Event.hpp"
#include "GameManager.hpp"

int     main(int ac, char **av)
{
    QApplication    app(ac, av);
    QFrame          *mainFrame = new QFrame;
    GameManager     engine(MAP_SIZE, MAP_SIZE, MAP_UNIT);
    EventManager    events(*mainFrame, engine, 2);
    Canvas          myCanvas(*mainFrame, QPoint(0, 0), QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1), engine);

    mainFrame->setWindowTitle("Nibbler");
    mainFrame->resize(QSize(MAP_SIZE * MAP_UNIT + 1, MAP_SIZE * MAP_UNIT + 1));
    mainFrame->show();

    events.show();
    myCanvas.show();

    app.exec();
    return (0);
}
