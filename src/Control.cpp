#include "Control.hpp"
#include <algorithm>
#include <fstream>
#include <regex>
#include <vector>

Control::Control() {
  std::cout << "INIT CONTROL VARIABLES" << std::endl;
  if (std::filesystem::exists(getFilepath("Max.asm"))) {
    this->readFile = std::fstream(getFilepath("Max.asm"));
  }
  this->writeFile = std::ofstream(getFilepath("Max.hack"));
  this->parser = Parser();
  this->code = Code();
  this->symbolTable = SymbolTable();
}
void Control::initControl() {
  std::cout << "STARTING CONTROL" << std::endl;
  firstPass();
  this->parser.resetParser();
  this->resetReadFile();
  secondPass();
  this->parser.resetParser();
  this->code.resetCode();
  this->writeFile.close();
  this->readFile.close();
  std::cout << "FINISHING CONTROL" << std::endl;
}
void Control::firstPass() {
  std::cout << "INIT FIRST PASS" << std::endl;
  std::string currentCommand;
  while (std::getline(this->readFile, currentCommand)) {
    currentCommand.erase(
        0, currentCommand.find_first_not_of(" \n\r\t")); // left trim
    currentCommand.erase(currentCommand.find_last_not_of("\t\n\v\f\r ") +
                         1); // right trim
    if (currentCommand.substr(0, 2) != "//" && currentCommand != "") {
      this->parser.setCommandType(currentCommand);
      if (this->parser.getCommandType() == C_COMMAND ||
          this->parser.getCommandType() == A_COMMAND) {
        this->symbolTable.romAddress += 1;
      } else {
        this->parser.setSymbol(currentCommand);
        this->symbolTable.addEntry(this->parser.getSymbol(),
                                   this->symbolTable.romAddress);
      }
    }
  }
  std::cout << "FINISHING FIRST PASS" << std::endl;
}
void Control::secondPass() {
  std::cout << "INIT SECOND PASS" << std::endl;
  std::string currentCommand;
  while (std::getline(this->readFile, currentCommand)) {
    currentCommand.erase(
        0, currentCommand.find_first_not_of(" \n\r\t")); // left trim
    currentCommand.erase(currentCommand.find_last_not_of("\t\n\v\f\r ") +
                         1); // right trim
    if (currentCommand.substr(0, 2) != "//" && currentCommand != "") {
      this->parser.setCommandType(currentCommand);
      if (parser.getCommandType() == L_COMMAND) {
        this->parser.resetParser();
        continue;
      }
      if (parser.getCommandType() == C_COMMAND) {
        // if is C_COMMAND
        parser.setDest(currentCommand);
        parser.setComp(currentCommand);
        parser.setJump(currentCommand);
        code.setDestBinary(parser.getDest());
        code.setCompBinary(parser.getComp());
        code.setJumpBinary(parser.getJump());
        code.setBinaryInstruction(C_COMMAND);
        this->writeFile << code.getBinaryInstruction();
      } else {
        this->parser.setSymbol(currentCommand);
        if (!isNumber(parser.getSymbol())) {
          if (this->symbolTable.contains(parser.getSymbol())) {
            this->parser.setSymbol(
                std::string("@") +
                std::to_string(
                    this->symbolTable.getRomAddress(this->parser.getSymbol())));
            code.setBinaryValue(parser.getSymbol());
          } else {
            this->symbolTable.addEntry(parser.getSymbol(),
                                       this->symbolTable.variablesCounter++);
            this->parser.setSymbol(std::string("@") + parser.getSymbol());
            code.setBinaryValue(std::to_string(
                this->symbolTable.getRomAddress(this->parser.getSymbol())));
          }
          code.setBinaryInstruction(A_COMMAND);
          this->writeFile << code.getBinaryInstruction();
        } else {
          code.setBinaryValue(parser.getSymbol());
          code.setBinaryInstruction(A_COMMAND);
          this->writeFile << code.getBinaryInstruction();
        }
      }
      this->writeFile << "\n";
      this->parser.resetParser();
      this->code.resetCode();
    }
  }
  std::cout << "FINISHING SECOND PASS" << std::endl;
}
void Control::resetReadFile() {
  this->readFile.clear();
  this->readFile.seekg(0, std::ios::beg);
}
