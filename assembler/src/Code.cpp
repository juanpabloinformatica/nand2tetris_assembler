#include "../include/Code.hpp"

void Code::setDestBinary(std::string currentDest) {
  C_INSTRUCTION_DEST destEnum = stringToDestEnum(currentDest);
  this->destBinary = std::bitset<DEST_BITS_LENGTH>(destEnum).to_string();
}
void Code::setCompBinary(std::string currentComp) {
  C_INSTRUCTION_COMP compEnum = stringToCompEnum(currentComp);
  this->compBinary = std::bitset<DEST_BITS_LENGTH>(compEnum).to_string();
}
void Code::setJumpBinary(std::string currentJump) {
  C_INSTRUCTION_JUMP jumpEnum = stringToJumpEnum(currentJump);
  this->jumpBinary = std::bitset<JUMP_BITS_LENGTH>(jumpEnum).to_string();
}

void Code::setBinaryInstruction(void) {
  if (this->destBinary == "" || this->compBinary == "" ||
      this->jumpBinary == "") {
    this->binaryInstruction = "";
    return;
  }
  this->binaryInstruction =
      this->destBinary + this->compBinary + this->jumpBinary;
}
