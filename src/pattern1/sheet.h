
#ifndef SHEET_H_
#define SHEET_H_

#include <string>
#include <list>

namespace design_pattern
{

class Cell;

class Sheet
{
public:
  explicit Sheet();
  ~Sheet() = default;

  std::string cellText(const int x, const int y);
  Cell* cell(const int x, const int y);
  std::list<Cell*>* getList();

  void setCellText(const int x, const int y, const std::string text);

  void undo();
  void redo();
  void disp();

private:
  std::list<std::list<Cell*> *> m_stack;
  int m_current;

  void addStack();
  bool isRedo();
};

} // design_pattern

#endif // SHEET_H_
