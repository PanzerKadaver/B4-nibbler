//
// mainLand.cpp for mainLand in /home/alois/rendu/nibbler/nibbler2.0
//
// Made by alois
// Login   <alois@epitech.net>
//
// Started on  Thu Mar 20 17:26:26 2014 alois
// Last update Thu Mar 20 20:33:50 2014 alois
//

#include <iostream>
#include "../Converter.hpp"
#include "../Land.hpp"

// clang++ mainLand.cpp Land.cpp Point.cpp -Werror -Wall -Wextra

void printLand(Land land)
{
  int w = land.GetWidth();
  int h = land.GetHeight();
  for (int i = 0; i < w; ++i)
    {
      for (int j = 0; j < h; ++j)
	std::cout << ((land.GetLand())[i][j]).GetContent();
      std::cout << std::endl;
    }
}

int main(int ac, char **av)
{
  int w = ac > 2 ? Converter::StringToNum<int>(std::string(av[1])) : 24;
  int h = ac > 2 ? Converter::StringToNum<int>(std::string(av[2])) : 12;

  Land land(h,w);
  printLand(land);
}
