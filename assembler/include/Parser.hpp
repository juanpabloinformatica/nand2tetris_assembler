#ifndef __PARSER__
#define __PARSER__
#include "Utilities.hpp"
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

class Parser {
private:
  std::string dest;
  std::string comp;
  std::string jump;
  std::string symbol;
  int indexCurrentInstruction;

public:
  std::fstream file;
  Parser(std::string filepath);
  bool hasMoreCommands();
  bool advance();
  COMMAND_TYPE getCommandType(std::string currentCommand);
  std::string getSymbol();
  std::string getDest();
  std::string getComp();
  std::string getJump();
  void setSymbol(std::string currentCommand);
  void setDest(std::string currentCommand);
  void setComp(std::string currentCommand);
  void setJump(std::string currentCommand);
  void setIndexCurrentInstruction(int indexCurrentInstruction);
  void resetParser(void);
  // ~Parser();
};
#endif
