
#include <memory>
#include <iostream>
#include "sheet.h"

using namespace design_pattern;

int main(int argc, char* argv[])
{
  Sheet sheet;
  sheet.setCellText(0, 0, "My angel mei.");
  sheet.setCellText(0, 1, "Hello, World");
  sheet.setCellText(0, 2, "straylight");
  sheet.disp();
  sheet.undo();
  sheet.disp();
  sheet.redo();
  sheet.disp();

  return 0;
}

