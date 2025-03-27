#include "../include/Parser.hpp"

Parser::Parser(std::string filepath) {
  std::cout << "[ INIT PARSING ]" << std::endl;
  this->file = std::fstream(filepath);
  this->dest = "";
  this->comp = "";
  this->jump = "";
  this->symbol = "";
  this->indexCurrentInstruction = 0;

  // std::regex expr{"^//"};
  // this->file = std::fstream(filepath);
  // std::string text;
  // while (std::getline(this->file, text)) {
  //   if (std::regex_match(text, expr)) {
  //   }
  //   std::remove_if(text.begin(), text.end(), isspace);
  // }
}
// bool Parser::hasMoreCommands() { return !this->file.eof(); }
// bool Parser::advance() { return this->hasMoreCommands(); }

COMMAND_TYPE Parser::getCommandType(std::string currentCommand) {
  COMMAND_TYPE commandType;
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
void Parser::setIndexCurrentInstruction(int indexCurrentInstruction) {
  this->indexCurrentInstruction = indexCurrentInstruction;
}
void Parser::setDest(std::string currentCommand) {
  std::string dest;
  std::string expr;
  std::string currentChar;
  int currentCommandLenght = currentCommand.length();
  expr = "=";
  dest = "";
  int i;
  for (i = this->indexCurrentInstruction;
       i < currentCommandLenght && (currentChar = currentCommand[i]) != expr;
       i++) {
    dest += currentChar;
  }
  if (i == currentCommandLenght) {
    this->dest = "";
    return;
  }
  this->setIndexCurrentInstruction(i + 1);
  this->dest = dest;
}
void Parser::setComp(std::string currentCommand) {
  std::string comp;
  std::string expr;
  std::string currentChar;
  int currentCommandLenght = currentCommand.length();
  expr = ";";
  comp = "";
  int i;
  for (i = this->indexCurrentInstruction;
       i < currentCommandLenght && (currentChar = currentCommand[i]) != expr;
       i++) {
    comp += currentChar;
  }
  this->setIndexCurrentInstruction(i + 1);
  this->comp = comp;
}
void Parser::setJump(std::string currentCommand) {
  std::string jump;
  std::string expr;
  std::string currentChar;
  int currentCommandLenght = currentCommand.length();
  expr = " ";
  jump = "";
  int i;
  for (i = this->indexCurrentInstruction;
       i < currentCommandLenght && (currentChar = currentCommand[i]) != expr;
       i++) {
    jump += currentChar;
  }
  this->setIndexCurrentInstruction(i + 1);
  this->jump = jump;
}
void Parser::setSymbol(std::string currentCommand) {
  if (currentCommand.substr(0, 1) == std::string("(") &&
      currentCommand.substr((currentCommand.length() - 1), 1) ==
          std::string(")")) {
    this->symbol = currentCommand.substr(1, currentCommand.length() - 2);
    return;
  }
  this->symbol = currentCommand.substr(1, currentCommand.length() - 1);
}
void Parser::resetParser(void) {
  this->dest = "";
  this->comp = "";
  this->jump = "";
  this->symbol = "";
  this->indexCurrentInstruction = 0;
}
std::string Parser::getSymbol() { return this->symbol; }
std::string Parser::getDest() { return this->dest; }
std::string Parser::getComp() { return this->comp; }
std::string Parser::getJump() { return this->jump; }
