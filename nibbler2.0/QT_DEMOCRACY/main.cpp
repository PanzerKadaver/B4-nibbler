#include <QtGui>
#include "keypress.hpp"
 
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
 
  KeyPress *keyPress = new KeyPress();
  keyPress->show();
 
  return a.exec();
}
