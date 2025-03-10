#include "Parser.hpp"
#include <cstring>
#include <fstream>
#include <ios>

Parser::Parser(std::string filepath) {
  std::cout << "Entering here" << std::endl;
  this->file = std::fstream(filepath);
  // std::cout<<this->file
  std::string text;
  while (std::getline(this->file, text)) {
    std::cout << "Has More commands:" << " [" << std::boolalpha
              << this->hasMoreCommands() << "]" << std::endl;
    std::cout << text << std::endl;
  }
  std::cout << "Has More commands:" << " [" << std::boolalpha
            << this->hasMoreCommands() << "]" << std::endl;
}
bool Parser::hasMoreCommands() { return !this->file.eof(); }
bool Parser::advance() { return this->hasMoreCommands(); }

CommandType Parser::getCommandType(std::string currentCommand) {
  CommandType commandType;
  if (currentCommand.substr(0, 1) == std::string("(") &&
      currentCommand.substr((currentCommand.length() - 1), 1) ==
          std::string(")")) {
    return L_COMMAND;
  }
  if (currentCommand.substr(0, 1) != std::string("@")) {
    return C_COMMAND;
  }
  return A_COMMAND;
  return commandType;
}
std::string Parser::getSymbol(std::string currentCommand) {
  if (currentCommand.substr(0, 1) == std::string("(") &&
      currentCommand.substr((currentCommand.length() - 1), 1) ==
          std::string(")")) {
    std::cout << "entering here???" << std::endl;
    return currentCommand.substr(1, currentCommand.length() - 2);
  }
  return currentCommand.substr(1, currentCommand.length() - 1);
}

std::string Parser::getDest(std::string currentCommand) {
  // this get d1,d2,d3 from c_instruction
  std::string destString = currentCommand.substr(D1, 2);
  return destString;
}
// #ifndef __VOITURE
// #define __VOITURE
// #include <iostream>
// class Voiture {
// public:
//   std::string band;
//   std::string model;
//   int year;
//   std::string show(void);
//   Voiture(std::string band, std::string model, int year);
// };
//
// #endif
// #include "Voiture.hpp"
// #include <iostream>
// using namespace std;
// string Voiture::show() {
//   return "band: " + this->band + "\nmodel: " + this->model +
//          "\nyear: " + to_string(this->year);
// };
// Voiture::Voiture(std::string band, std::string model, int year) {
//   this->band = band;
//   this->model = model;
//   this->year = year;
// };
