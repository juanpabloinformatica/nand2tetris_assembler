#include "../include/Utilities.hpp"

unsigned long int bitsToULong(std::string instructionString,
                              C_INSTRUCTION_SECTION section, int initPos) {
  switch (section) {
  case C_DEST:
    return (std::bitset<DEST_BITS_LENGTH>(
                instructionString.substr(INS_D1, DEST_BITS_LENGTH)))
        .to_ullong();
    break;
  case C_COMP:
    return (std::bitset<COMP_BITS_LENGTH>(
                instructionString.substr(INS_D1, COMP_BITS_LENGTH)))
        .to_ullong();
    break;
  case C_JUMP:
    return (std::bitset<JUMP_BITS_LENGTH>(
                instructionString.substr(INS_D1, JUMP_BITS_LENGTH))
                .to_ullong());
    break;
  default:
    return C_UNDEFINED;
  }
};
