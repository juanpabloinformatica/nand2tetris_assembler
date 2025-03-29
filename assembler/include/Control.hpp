#ifndef __CONTROL__
#define __CONTROL__
#include "Code.hpp"
#include "Parser.hpp"
#include "Utilities.hpp"
#define READ_FILEPATH "../testFiles/Add.asm"
#define WRITE_FILEPATH "../testFiles/Add.hack"

#include <fstream>
#include <iostream>
#include <regex>
class Control {
public:
  Parser parser;
  Code code;
  std::fstream readFile;
  std::ofstream writeFile;
  Control();
  void initControl();
};
#endif
