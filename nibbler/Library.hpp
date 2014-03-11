#ifndef NIBBLER_LIBRARY_HPP_
# define NIBBLER_LIBRARY_HPP_

# if defined(__GNUG__)
#  include <dlfcn.h>
#elif defined(_MSC_VER)
#  include <Windows.h>
#  include <atlstr.h>
#  include <string>
# else
#  error G++ or MS compiler required
#endif

namespace Library
{
# if defined(_MSC_VER)
	void convert_name(std::string &dllName)
	{
	  const size_t pos = dllName.rfind(".so");

	  if (pos != std::string::npos)
	    dllName.replace(pos, std::string::npos, ".dll");
	}
#endif
	void	*open(const char *filename)
	{
# if defined(__GNUG__)
		return dlopen(filename, RTLD_LAZY);
# elif defined(_MSC_VER)
		std::string dllName(filename);
		convert_name(dllName);
		std::cout << dllName << std::endl;
		return LoadLibrary(CStringW(dllName.c_str()));
# else
#		error G++ or MS compiler required
# endif
	}

	void	*sym(void *handle, const char *symbol)
	{
# if defined(__GNUG__)
		return dlsym(handle, symbol);
# elif defined(_MSC_VER)
		return GetProcAddress(reinterpret_cast<HMODULE>(handle), symbol);
# else
#		error G++ or MS compiler required
# endif
	}

	char	*error(void)
	{
# if defined(__GNUG__)
		return dlerror();
# elif defined(_MSC_VER)
		int len, error_code;
		static char errstr[128];

		if((error_code = GetLastError()) == 0)
			return((char *)0);
		/*POSIX dlerror call needs to report no error(null)
		when it is called 2nd time consequently, so clear error*/
		SetLastError(0);
		/*format the error string*/
		len = sprintf_s(errstr, "Error <%d>", error_code);
		len += FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			error_code,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), /* Default language */
			(LPTSTR) errstr + len,
			sizeof(errstr) - len,
			NULL
			);
		/*replace \r\n*/
		if (len > 1 && errstr[len-2] == '\r' && errstr[len-1] == '\n') {
			if (len > 2 && errstr[len-3] == '.')
				len--;
		}
		return errstr;
# else
#		error G++ or MS compiler required
# endif
	}

	int		close(void *handle)
	{
# if defined(__GNUG__)
		return dlclose(handle);
# elif defined(_MSC_VER)
		if (FreeLibrary(reinterpret_cast<HMODULE>(handle)) == 0)
			return GetLastError();
		return 0;
# else
#		error G++ or MS compiler required
# endif
	}
}

#endif
