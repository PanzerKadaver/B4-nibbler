#include <iostream>
#include <cstdlib>

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
