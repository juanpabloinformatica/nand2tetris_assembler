#include "Parser.hpp"
#include "Utilities.hpp"
#include <bitset>
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
    return currentCommand.substr(1, currentCommand.length() - 2);
  }
  return currentCommand.substr(1, currentCommand.length() - 1);
}

// std::string Parser::getDest(std::string currentCommand) {
//   // this get d1,d2,d3 from c_instruction
//   std::string destString = currentCommand.substr(D1, 3);
//   std::bitset<3> destBits(destString);
//   switch (destBits.to_ullong()) {
//   case null:
//       return null;
//     break;
//   case M:
//     break;
//   case D:
//     break;
//   case MD:
//     break;
//   case A:
//     break;
//   case AM:
//     break;
//   case AD:
//     break;
//   case AMD:
//     break;
//   }
//   return destString;
// }

C_INSTRUCTION_DEST Parser::getDest(std::string currentCommand) {
  // this get d1,d2,d3 from c_instruction
  std::string destString =
      currentCommand.substr(INS_D1, DESTINATION_BITS_LENGTH);
  std::bitset<DESTINATION_BITS_LENGTH> destBits(destString);
  switch (destBits.to_ullong()) {
  case DEST_null:
    return DEST_null;
    break;
  case DEST_M:
    return DEST_M;
    break;
  case DEST_D:
    return DEST_D;
    break;
  case DEST_MD:
    return DEST_MD;
    break;
  case DEST_A:
    return DEST_A;
    break;
  case DEST_AM:
    return DEST_AM;
    break;
  case DEST_AD:
    return DEST_AD;
    break;
  case DEST_AMD:
    return DEST_AMD;
    break;
  default:
    return DEST_UNDEFINED;
  }
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
