//
// tstQT.cpp for  in /home/aubert_n/rep/nibbler/nibbler2.0/QtPourLesNuls
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Tue Apr  1 13:02:05 2014 Nathan AUBERT
// Last update Tue Apr  1 13:07:41 2014 Nathan AUBERT
//

#include "tstQT.hpp" 

int		main(int argc, char** argv)
{
  QApplication	app(argc, argv);
  MyTest	test;

  test.show();
  app.exec();

  return 0;
}
