//
// Traductor.cpp for Traductor in /home/alois/rendu/nibbler/nibbler
// 
// Made by alois
// Login   <alois@epitech.net>
// 
// Started on  Tue Mar 18 19:14:14 2014 alois
// Last update Tue Mar 18 19:16:47 2014 alois
//

#include "Traductor.hpp"

Traductor::Traductor()
{
  this->dico[' '] = "empty";
  this->dico['b'] = "border";
  this->dico['s'] = "snake";
  this->dico['f'] = "food";
}
