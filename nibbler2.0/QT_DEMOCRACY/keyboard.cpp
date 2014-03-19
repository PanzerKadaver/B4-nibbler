#include "keypress.hpp"
 
#include <QApplication>
#include <QKeyEvent>
 
KeyPress::KeyPress(QWidget *parent) :
  QWidget(parent)
{
  myLabel = new QLabel("LABEL");
  mainLayout = new QVBoxLayout;
  mainLayout->addWidget(myLabel);
  setLayout(mainLayout);
 
}
 
void KeyPress::keyPressEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Escape)
    {
      myLabel->setText("You pressed ESC");
    }
}
 
void KeyPress::keyReleaseEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Escape)
    {
      myLabel->setText("You released ESC");
    }
}
