
#ifndef SHEET_WITH_MEMENTO_H_
#define SHEET_WITH_MEMENTO_H_

#include <string>
#include <list>
#include "cell.h"

class CellMemento;

namespace design_pattern
{

class SheetWithMemento
{
public:
  explicit SheetWithMemento() : m_current(-1) {}
  ~SheetWithMemento();

  std::string cellText(const int x, const int y);
  Cell* cell(const int x, const int y);

  void setCellText(const int x, const int y, const std::string text);
  void undo();
  void redo();
  void disp();

private:
  std::list<CellMemento*> m_stack;
  std::list<Cell*> m_cellList;
  int m_current;

  std::list<Cell*>* getList() { return &m_cellList; }
  void addStack(Cell* pOldCell, Cell* pNewCell);
  bool isRedo();
};

} // design_pattern

#endif // SHEET_WITH_MEMENTO_H_
