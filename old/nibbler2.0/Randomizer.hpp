//
// RandList.hpp for Randomizer in /tmp/nibbler/nibbler2.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Apr  1 13:27:35 2014 alois
// Last update Tue Apr  1 14:43:55 2014 alois
//

#ifndef RANDOMIZER_HPP_
# define RANDOMIZER_HPP_

#include <cstdlib>
#include <iostream>
#include <ctime>

namespace Randomizer
{
  /*
  template <typename C>
  static typename C::value_type GetItemFromContainer(const C &container) {
    srand(time(NULL));
    typename C::value_type randItem;
    randItem = container[std::rand() % container.size()];
    return randItem;
    }
  */

  template <typename C> // here C is a vector or a deque ; C should support [] operator !
  static typename C::value_type GetItem(const C &container) {
    srand(time(NULL)); // Initializes the random seed
    return container[std::rand() % container.size()];
  }
}

#endif
