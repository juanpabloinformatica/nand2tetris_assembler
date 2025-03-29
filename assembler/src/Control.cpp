#include "Control.hpp"
#include <fstream>
#include <regex>

Control::Control() {
  std::cout << "INIT CONTROL VARIABLES" << std::endl;
  if (std::filesystem::exists(getFilepath("RectL.asm"))) {
    this->readFile = std::fstream(getFilepath("RectL.asm"));
  }
  this->writeFile = std::ofstream(getFilepath("RectL.hack"));
  this->parser = Parser();
  this->code = Code();
}
void Control::initControl() {
  std::cout << "STARTING CONTROL" << std::endl;
  std::string currentCommand;
  std::regex expr{"^//"};
  while (std::getline(this->readFile, currentCommand)) {
    // if (!(std::regex_match(currentCommand, expr))) {
    if (currentCommand.substr(0, 2) != "//" && currentCommand != "\r") {
      parser.setCommandType(currentCommand);
      if (parser.getCommandType() == C_COMMAND) {
        // currentCommand = currentCommand.substr(0, currentCommand.length() - 1);
        std::cout << currentCommand << std::endl;
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
        // some instructions
        if (parser.getCommandType() == A_COMMAND) {
          parser.setSymbol(currentCommand);
          code.setBinaryValue(parser.getSymbol());
          code.setBinaryInstruction(A_COMMAND);
          this->writeFile << code.getBinaryInstruction();
        } else {
          // Not done it yet
        }
      }
      this->writeFile << "\n";
      parser.resetParser();
      code.resetCode();
    }
  }
  this->writeFile.close();
  std::cout << "FINISHING CONTROL" << std::endl;
}
