
#ifndef CELL_H_
#define CELL_H_

#include <string>

namespace design_pattern
{

class Cell
{
public:
  explicit Cell(const int x, const int y, std::string text) : m_x(x), m_y(y), m_text(text) {}
  ~Cell() = default;

  int x() { return m_x; }
  int y() { return m_y; }
  std::string text() { return m_text; }
  void setText(const std::string text) { m_text = text; }
  Cell* clone() { return new Cell(m_x, m_y, m_text); }

private:
  int m_x;
  int m_y;
  std::string m_text;
};

} // design_pattern

#endif // CELL_H_
