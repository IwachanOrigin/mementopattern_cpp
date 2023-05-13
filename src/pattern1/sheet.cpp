
#include <iostream>
#include "cell.h"
#include "sheet.h"

using namespace design_pattern;

Sheet::Sheet()
  : m_current(0)
{
  m_stack.push_back(new std::list<Cell*>);
}

std::string Sheet::cellText(const int x, const int y)
{
  auto pCell = cell(x, y);
  if (pCell != nullptr)
  {
    return pCell->text();
  }
  return "";
}

Cell* Sheet::cell(const int x, const int y)
{
  auto list = getList();
  std::list<Cell*>::iterator it = list->begin();
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

std::list<Cell*>* Sheet::getList()
{
  //std::list<std::list<Cell*> *>::iterator it = m_stack.begin();
  auto it = m_stack.begin();
  for (int i = 0; it != m_stack.end(); it++, i++)
  {
    if (m_current == i)
    {
      return (*it);
    }
  }
  return nullptr;
}

void Sheet::setCellText(const int x, const int y, const std::string text)
{
  this->addStack();
  auto pCell = cell(x, y);
  if (pCell != nullptr)
  {
    pCell->setText(text);
  }
  else
  {
    getList()->push_back(new Cell(x, y, text));
  }
}

void Sheet::undo()
{
  if (m_current > 0)
  {
    m_current--;
  }
}

void Sheet::redo()
{
  if (this->isRedo())
  {
    m_current++;
  }
}

void Sheet::disp()
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

bool Sheet::isRedo()
{
  return m_current < ((int)m_stack.size() - 1);
}

void Sheet::addStack()
{
  while (this->isRedo())
  {
    //std::list<std::list<Cell*> *>::iterator itCells = m_stack.begin();
    auto itCells = m_stack.begin();
    // ref: https://cpprefjp.github.io/reference/iterator/advance.html
    std::advance(itCells, (m_stack.size() - 1));

    // Delete cells object before delete Sheet objects
    // std::list<Cell*>::iterator itCell = (*itCells)->begin();
    auto itCell = (*itCells)->begin();
    while (itCell != (*itCells)->end())
    {
      delete (*itCell);
      (*itCell) = nullptr;
      itCell++;
    }
    // Delete list
    delete (*itCells);
    (*itCells) = nullptr;
    m_stack.erase(itCells);
  }

  //std::list<Cell*>* pNewCells = new std::list<Cell*>;
  auto pNewCells = new std::list<Cell*>;
  auto list = getList();
  auto itCell = list->begin();
  while (itCell != list->end())
  {
    pNewCells->push_back((*itCell)->clone());
    itCell++;
  }
  m_stack.push_back(pNewCells);
  m_current++;
}
