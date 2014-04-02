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
