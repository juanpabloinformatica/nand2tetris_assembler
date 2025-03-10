#ifndef __PARSER__
#define __PARSER__
#include <fstream>
#include <iostream>
#include <string>
enum CommandType { A_COMMAND, L_COMMAND, C_COMMAND };
enum CInstructionBits {
  OP_CODE,
  DEFAULT_1,
  DEFAULT_2,
  A_VALUE,
  C1,
  C2,
  C3,
  C4,
  C5,
  C6,
  D1,
  D2,
  D3,
  J1,
  J2,
  J3
};
enum C_NEMONIC { null, M, D, MD, A, AM, AD, AMD };
// class Command {
// public:
//   std::string command;
//   CommandType commandType;
//   Command(std::string command, CommandType commandType);
// };
class Parser {

public:
  std::fstream file;
  Parser(std::string filepath);
  bool hasMoreCommands();
  bool advance();
  CommandType getCommandType(std::string currentCommand);
  // std::string getSymbol(Command currentCommand);
  // std::string getDest(Command currentCommand);
  // std::string getComp(Command currentCommand);
  // std::string getJump(Command currentCommand);
  std::string getSymbol(std::string currentCommand);
  std::string getDest(std::string currentCommand);
  std::string getComp(std::string currentCommand);
  std::string getJump(std::string currentCommand);
};
#endif
