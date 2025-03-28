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
  COMMAND_TYPE commandType;
  int indexCurrentInstruction;

public:
  std::fstream file;
  Parser();
  bool hasMoreCommands();
  bool advance();
  COMMAND_TYPE getCommandType();
  std::string getSymbol();
  std::string getDest();
  std::string getComp();
  std::string getJump();
  void setCommandType(std::string currentCommand);
  void setSymbol(std::string currentCommand);
  void setDest(std::string currentCommand);
  void setComp(std::string currentCommand);
  void setJump(std::string currentCommand);
  void setIndexCurrentInstruction(int indexCurrentInstruction);
  void resetParser(void);
  // ~Parser();
};
#endif
