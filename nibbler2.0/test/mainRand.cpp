//
// mainRand.cpp for mainRand in /tmp/nibbler/nibbler2.0
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Apr  1 14:18:21 2014 alois
// Last update Tue Apr  1 14:44:17 2014 alois
//


#include <iostream>
#include <string>
#include <deque>
#include "../Randomizer.hpp"

int main()
{
  std::deque<std::string> v;
  v.push_back("1toto");
  v.push_back("2toto");
  v.push_back("3toto");
  v.push_back("4toto");
  std::string s = Randomizer::GetItem<std::deque<std::string> >(v);
  std::cout << s << std::endl;
}
