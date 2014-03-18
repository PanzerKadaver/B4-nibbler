#include <iostream>
#include <cstdlib>
#include <QtGui/qapplication.h>
#include <QtGui/qpushButton.h>

#include "Library.hpp"

void		pause();
int			appRun(int, char **);

int     main(int ac, char **av)
{
    int err_code = 0;

    //    err_code = appRun(ac, av);
    err_code = run();

    std::cout << std::endl;
    pause();
    return (err_code);
}

int			appRun(int ac, char **av)
{
    typedef void (*func)();
    void	*libhandler;
    func	test1;

    if (!(libhandler = Library::open("./lib_nibbler_QT.so")))
    {
        std::cerr << Library::error() << std::endl;
        abort();
    }
    else
        std::cout << "Lib sucessfully loaded" << std::endl;
    if (!(test1 = reinterpret_cast<func>(Library::sym(libhandler, "ex_test"))))
    {
        std::cerr << Library::error() << std::endl;
        abort();
    }
    else
        std::cout << "Function loaded" << std::endl;
    test1();
    if (!Library::close(libhandler))
        std::cout << "Library unloaded" << std::endl;
    else
    {
        std::cerr << Library::error() << std::endl;
        abort();
    }

    QApplication app(ac, av);

    QPushButton bouton("Bonjour les Zeros !");
    bouton.show();

    QObject::connect(&bouton, SIGNAL(clicked()), &app, SLOT(quit()));

    return app.exec();
}

void		pause()
{
#if defined(_MSC_VER)
    system("PAUSE");
#else
    std::cout << "Press key to continue..." <<std::endl;
    std::cin.get();
#endif
}
