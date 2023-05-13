
#include <memory>
#include <iostream>
#include "sheetwithmemento.h"

using namespace design_pattern;

int main(int argc, char* argv[])
{
  SheetWithMemento sheet;
  sheet.setCellText(0, 0, "My angel mei.");
  sheet.setCellText(0, 1, "Hello, World");
  sheet.setCellText(0, 2, "straylight");
  std::cout << "After added." << std::endl;
  sheet.disp();

  sheet.undo();
  std::cout << std::endl;
  std::cout << "After undo." << std::endl;
  sheet.disp();

  sheet.redo();
  std::cout << std::endl;
  std::cout << "After redo." << std::endl;
  sheet.disp();

  return 0;
}

