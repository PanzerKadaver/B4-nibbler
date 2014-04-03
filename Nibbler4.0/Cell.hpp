//
// Cell.hpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:16 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:17 2014 Nathan AUBERT
//

#ifndef NIBLER_CELL_HPP_
# define NIBLER_CELL_HPP_

#include <QtCore/QPoint>

class Cell
{
public:
  Cell(const QPoint &);
  Cell(uint, uint);
  ~Cell(void) {};

  char    getContent(void) const;
  void    setContent(char);

private:
  QPoint  _coord;
  char    _content;
};

#endif /* !NIBLER_CELL_HPP_ */
