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
  int indexCurrentInstruction;

public:
  std::fstream file;
  Parser(std::string filepath);
  bool hasMoreCommands();
  bool advance();
  COMMAND_TYPE getCommandType(std::string currentCommand);
  std::string getSymbol(std::string currentCommand);
  std::string getDest();
  std::string getComp();
  std::string getJump();
  void setDest(std::string dest);
  void setComp(std::string comp);
  void setJump(std::string jump);
  void setIndexCurrentInstruction(int indexCurrentInstruction);
  void resetParser(void);
  // ~Parser();
};
#endif
