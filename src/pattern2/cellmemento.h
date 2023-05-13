
#ifndef CELL_MEMENTO_H_
#define CELL_MEMENTO_H_

#include "cell.h"

namespace design_pattern
{

class CellMemento
{
public:
  explicit CellMemento(Cell* pOldCell, Cell* pNewCell);
  ~CellMemento();

  Cell* newCell() { return m_pNewCell; }
  Cell* oldCell() { return m_pOldCell; }

private:
  Cell* m_pOldCell;
  Cell* m_pNewCell;
};

} // design_pattern

#endif // CELL_MEMENTO_H_
