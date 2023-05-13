
#include <iostream>
#include "cellmemento.h"
#include "sheetwithmemento.h"

using namespace design_pattern;

SheetWithMemento::~SheetWithMemento()
{
  auto it = m_stack.begin();
  while (it != m_stack.end())
  {
    delete (*it);
    (*it) = nullptr;
    it++;
  }
}

std::string SheetWithMemento::cellText(const int x, const int y)
{
  auto pCell = cell(x, y);
  if (pCell != nullptr)
  {
    return pCell->text();
  }
  return "";
}

Cell* SheetWithMemento::cell(const int x, const int y)
{
  auto list = getList();
  //std::list<Cell*>::iterator it = list->begin();
  auto it = list->begin();
  while (it != list->end())
  {
    Cell* pCell = (*it);
    if ((pCell->x() == x) && (pCell->y() == y))
    {
      return pCell;
    }
    it++;
  }
  return nullptr;
}

void SheetWithMemento::setCellText(const int x, const int y, const std::string text)
{
  auto pCell = cell(x, y);
  auto pOldCell = pCell;
  auto pNewCell = pCell;

  if (pCell)
  {
    pOldCell = (Cell*)pCell->clone();
    pCell->setText(text);
  }
  else
  {
    pNewCell = new Cell(x, y, text);
    this->getList()->push_back(pNewCell);
  }

  this->addStack(pOldCell, pNewCell);
}

void SheetWithMemento::undo()
{
  if (m_current > 0)
  {
    m_current--;
  }

  auto it = m_stack.begin();
  for (int i = 0; it != m_stack.end(); it++, i++)
  {
    if (m_current == i)
    {
      break;
    }
  }

  auto memento = (*it);
  m_cellList.remove(memento->newCell());
  if (memento->oldCell() != nullptr)
  {
    m_cellList.remove(memento->oldCell());
  }

  if (m_current >= 0)
  {
    m_current--;
  }
}

void SheetWithMemento::redo()
{
  if (!this->isRedo())
  {
    return;
  }

  m_current++;
  auto it = m_stack.begin();
  for (int i = 0; it != m_stack.end(); it++, i++)
  {
    if (m_current == i)
    {
      break;
    }
  }

  auto memento = (*it);
  m_cellList.remove(memento->newCell());
  if (memento->oldCell() != nullptr)
  {
    m_cellList.remove(memento->oldCell());
  }
  m_cellList.push_back(memento->newCell());
}

void SheetWithMemento::disp()
{
  auto list = getList();
  auto it = list->begin();
  while (it != list->end())
  {
    std::cout << "x: " << (*it)->x() << " ";
    std::cout << "y: " << (*it)->y() << " ";
    std::cout << "text: " << (*it)->text() << std::endl;
    it++;
  }
}

void SheetWithMemento::addStack(Cell* pOldCell, Cell* pNewCell)
{
  while (this->isRedo())
  {
    //std::list<std::list<Cell*> *>::iterator itCells = m_stack.begin();
    auto it = m_stack.begin();
    // ref: https://cpprefjp.github.io/reference/iterator/advance.html
    std::advance(it, (m_stack.size() - 1));
    m_stack.erase(it);
  }

  m_stack.push_back(new CellMemento(pOldCell, pNewCell));
  m_current++;
}

bool SheetWithMemento::isRedo()
{
  return m_current < ((int)m_stack.size() - 1);
}

