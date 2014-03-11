#include <iostream>

# if defined(__GNUG__)
# define DLLEXPORT /*Nothing to do here*/
#elif defined(_MSC_VER)
# define DLLEXPORT __declspec(dllexport)
# else
#  error G++ or MS compiler required
#endif


extern "C"
{
	DLLEXPORT void ex_test()
	{
		std::cout << "I'm talking ! Biatch !" << std::endl;
	}
}
