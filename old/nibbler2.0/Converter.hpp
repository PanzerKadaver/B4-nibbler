//
// Converter.hpp for Converter in /home/alois/Code/c++/lib
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Mon Feb 17 14:49:04 2014 alois
// Last update Mon Feb 17 15:32:50 2014 alois
//

#ifndef CONVERTER_HPP_
# define CONVERTER_HPP_

#include <sstream>
#include <string>

namespace Converter
{
  template <typename T>
  static std::string NumToString(T num) {
    std::ostringstream ss;
    ss << num;
    return ss.str();
  }

  template <typename T>
  static T StringToNum(const std::string &s) {
    std::istringstream ss(s);
    T num;
    return ss >> num ? num : 0;
  }
}

#endif
