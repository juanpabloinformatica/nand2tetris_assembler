#include "../include/Code.hpp"

Code::Code() {};
void Code::setDestBinary(std::string currentDest) {
  C_INSTRUCTION_DEST destEnum = stringToDestEnum(currentDest);
  this->destBinary = std::bitset<DEST_BITS_LENGTH>(destEnum).to_string();
}
void Code::setCompBinary(std::string currentComp) {
  C_INSTRUCTION_COMP compEnum = stringToCompEnum(currentComp);
  this->compBinary = std::bitset<COMP_BITS_LENGTH>(compEnum).to_string();
}
void Code::setJumpBinary(std::string currentJump) {
  C_INSTRUCTION_JUMP jumpEnum = stringToJumpEnum(currentJump);
  this->jumpBinary = std::bitset<JUMP_BITS_LENGTH>(jumpEnum).to_string();
}

void Code::setBinaryInstruction(COMMAND_TYPE type) {
  if (this->destBinary == "" || this->compBinary == "" ||
      this->jumpBinary == "") {
    this->binaryInstruction = "";
    return;
  }
  if (type == C_COMMAND) {
    this->binaryInstruction =
        "111" + this->compBinary + this->destBinary + this->jumpBinary;
  }
}

std::string Code::getDestBinary(void) { return this->destBinary; }
std::string Code::getCompBinary(void) { return this->compBinary; }
std::string Code::getJumpBinary(void) { return this->jumpBinary; }
std::string Code::getBinaryInstruction(void) { return this->binaryInstruction; }
