//
// QtEvents.hpp for  in /home/aubert_n/rep/nibbler/nibbler2.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Fri Mar 21 20:29:16 2014 Nathan AUBERT
// Last update Sat Mar 22 00:23:07 2014 Nathan AUBERT
//

#ifndef QTEVENTS_HPP_
# define QTEVENTS_HPP_

# include	<QtGui/QtGui>
# include	<QtCore/QtCore>

class	MyQtClass : public QWidget
{
public:
  MyQtClass (QWidget *parent = 0, Qt::WindowFlags f = 0) : QWidget (parent, f){};

protected:
  void	keyPressEvent(QKeyEvent *event)
  {
    //    qDebug()<<event->text();
    event->accept();
    std::cout << "key == " << event->key() << std::endl;

    if (event->key() == 16777235){std::cout<<"up"<<std::endl;}
    if (event->key() == 16777237){std::cout<<"down"<<std::endl;}
    if (event->key() == 16777234){std::cout<<"left"<<std::endl;}
    if (event->key() == 16777236){std::cout<<"right"<<std::endl;}
    if (event->key() == 16777216){std::cout<<"escape"<<std::endl; return;}
  }
};

#endif /* QTEVENTS_HPP_ */
