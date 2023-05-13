
#include "cellmemento.h"

using namespace design_pattern;

CellMemento::CellMemento(Cell *pOldCell, Cell *pNewCell)
  : m_pOldCell(pOldCell)
  , m_pNewCell(pNewCell)
{
}

CellMemento::~CellMemento()
{
  if (m_pOldCell)
  {
    delete m_pOldCell;
    m_pOldCell = nullptr;
  }
  if (m_pNewCell)
  {
    delete m_pNewCell;
    m_pNewCell = nullptr;
  }
}

