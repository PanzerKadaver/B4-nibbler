//
1;2802;0c// Apple.hpp for Apple in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Mon Mar 17 23:59:38 2014 alois
// Last update Tue Mar 18 00:20:26 2014 alois
//

#ifndef APPLE_HPP_
# define APPLE_HPP_

# include "AFoodItem.hpp"

class Apple : public AFoodItem
{
public:
  Apple() : AFoodItem("apple", 10) {}
  ~Apple() {}
};

#endif
