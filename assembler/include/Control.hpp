#ifndef __CONTROL__
#define __CONTROL__
#include "Code.hpp"
#include "Parser.hpp"
#define FILEPATH "../helper/file.hack"
#include <iostream>
#include <regex>
class Control {
public:
  Parser parser;
  Code code;
  std::fstream file;
  Control();
  void initControl();
};
#endif
