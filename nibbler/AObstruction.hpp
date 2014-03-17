//
// AObstruction.hpp for AObstruction.hpp in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 00:21:07 2014 alois
// Last update Tue Mar 18 00:25:46 2014 alois
//

#ifndef AOBSTRUCTION_HPP_
# define AOBSTRUCTION_HPP_

# include "IContent.hpp"

class AObstruction : public IContent
{
public:
  AObstruction() {};
  virtual ~AObstruction() {}

  virtual void LaunchEvent() { /* throw error to close the game ?*/ }
};

#endif
