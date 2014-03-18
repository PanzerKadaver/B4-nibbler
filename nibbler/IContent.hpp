//
// IContent.hpp for Icontent.hpp in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Mon Mar 17 23:40:48 2014 alois
// Last update Tue Mar 18 12:40:55 2014 alois
//

#ifndef ICONTENT_HPP_
# define ICONTENT_HPP_

/*
** ToDo :
** Add image aka a way to represent the item
** It could be a simple char or an int for example.
*/

class IContent
{
public:
  virtual ~IContent {}
  virtual void LaunchEvent() = 0; // increase the score, lose the game, etc.
};

#endif
