#ifndef __CONTROL__
#define __CONTROL__
#include "Code.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"
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
  SymbolTable symbolTable;
  std::fstream readFile;
  std::ofstream writeFile;
  Control();
  void initControl();
  void firstPass();
  void secondPass();
  void resetReadFile();
};
#endif
