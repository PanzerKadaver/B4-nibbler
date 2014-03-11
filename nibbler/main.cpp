#include <iostream>

#include "Library.hpp"

void		pause();
int			appRun();

int			main()
{
	int		err_code = 0;

	err_code = appRun();
	std::cout << std::endl;
	pause();
	return (err_code);
}

int			appRun()
{
	void	*libhandler;
	void	*test1;;

	if (!(libhandler = Library::open("lib_nibbler_QT")))
		std::cerr << Library::error() << std::endl;
	else
		std::cout << "Lib sucessfully loaded" << std::endl;
	if (!(test1 = Library::sym(libhandler, "ex_test")))
		std::cerr << Library::error() << std::endl;
	else
		std::cout << "Function loaded" << std::endl;
	return 0;
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
