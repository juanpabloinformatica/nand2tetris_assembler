#include "Control.hpp"
#include <regex>

Control::Control() {
  std::cout << "INIT CONTROL VARIABLES";
  std::string filepath = FILEPATH;
  this->file = std::fstream(filepath);
  this->parser = Parser();
  this->code = Code();
}
void Control::initControl() {
  std::cout << "STARTING CONTROL";
  std::string currentCommand;
  std::regex expr{"^//"};
  while (std::getline(this->file, currentCommand)) {
    if (!(std::regex_match(currentCommand, expr))) {
      if(parser.getCommandType(text)==A_COMMAND){

      }else if(parser.getCommandType(text)==){

      }
    }
  }
}
