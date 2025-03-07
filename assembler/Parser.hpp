#ifndef __PARSER__
#define __PARSER__
#include <fstream>
#include <iostream>
#include <string>
enum CommandType { A_COMMAND, C_COMMAND, L_COMMAND };
class Command {
public:
  std::string command;
  CommandType commandType;
  Command(std::string command, CommandType commandType);
};
class Parser {

public:
  std::fstream file;
  Parser(std::string filepath);
  bool hasMoreCommands();
  void advance();
  CommandType commandType(Command currentCommand);
  std::string symbol(Command currentCommand);
  std::string dest(Command currentCommand);
  std::string comp(Command currentCommand);
  std::string jump(Command currentCommand);
};
#endif
