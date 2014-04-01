//
// Traductor.hpp for Traductor in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 19:08:25 2014 alois
// Last update Fri Mar 21 14:57:16 2014 Nathan AUBERT
//

#ifndef TRADUCTOR_HPP_
# define TRADUCTOR_HPP_

# include <map>
# include <string>

class Traductor
{
public:
  Traductor();
  ~Traductor() {}
  std::string getName(char c) { return dico[c]; }

private:
  std::map<char, std::string> dico;
};

#endif
