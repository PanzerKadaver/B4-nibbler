//
// tstQT.hpp for  in /home/aubert_n/qt
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Fri Mar 21 14:35:46 2014 Nathan AUBERT
// Last update Tue Apr  1 13:14:23 2014 Nathan AUBERT
//

#ifndef tstQT_HPP_
# define tstQT_HPP_

# include <QtGui/QtGui>
# include <QtCore/QtCore>
# include <iostream>

class	MyTest : public	QWidget
{
public:
MyTest ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
  : QWidget  (parent,f){};

protected: 
  void	keyPressEvent(QKeyEvent *event)
  {
    event->accept();
    std::cout << "key == " << event->key() << std::endl;
    std::cout << "toto" << std::endl;
    if (event->key() == 16777251)
      return;
  }
};

#endif /* tstQT_HPP_ */
