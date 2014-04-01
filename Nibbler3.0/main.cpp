#include <QtGui\QApplication>
#include <QtGui\QFrame>

#include "Nibbler.hpp"
#include "Canvas.hpp"
#include "Event.hpp"

int     main(int ac, char **av)
{
    QApplication    app(ac, av);
    QFrame          *mainFrame = new QFrame;
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
