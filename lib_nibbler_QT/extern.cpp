#include <iostream>

#include "Header.h"

# if defined(__GNUG__)
# define EXPORT /*Nothing to do here*/
#elif defined(_MSC_VER)
# define EXPORT __declspec(dllexport)
# else
#  error G++ or MS compiler required
#endif


extern "C"
{
    EXPORT void ex_test() { test(); };
}
