//
// tstQT.hpp for  in /home/aubert_n/qt
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Fri Mar 21 14:35:46 2014 Nathan AUBERT
// Last update Fri Mar 21 14:42:58 2014 Nathan AUBERT
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
    qDebug()<<event->text();
    event->accept();
std::cout << "key == " << event->key() << std::endl;

  }
};

#endif /* tstQT_HPP_ */
