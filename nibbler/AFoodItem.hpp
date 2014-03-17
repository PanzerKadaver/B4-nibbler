//
// AFoodItem.hpp for AFoodItem in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Mon Mar 17 23:49:41 2014 alois
// Last update Tue Mar 18 00:19:27 2014 alois
//

#ifndef AFOODITEM_HPP_
# define AFOODITEM_HPP_

# include "IContent.hpp"

class AFoodItem : public IContent
{
public:
  AFoodItem(const std::string &n, int b) : name(n), bonus(b) {}
  virtual ~AFoodItem() {}

  virtual void launchEvent() { _score += bonus; }

protected:
  std::string	name;
  int		bonus;
};

#endif
