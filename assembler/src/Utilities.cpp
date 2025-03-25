#include "../include/Utilities.hpp"
#include <cstring>

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
                instructionString.substr(INS_A_VALUE, COMP_BITS_LENGTH)))
        .to_ullong();
    break;
  case C_JUMP:
    return (std::bitset<JUMP_BITS_LENGTH>(
                instructionString.substr(INS_J1, JUMP_BITS_LENGTH))
                .to_ullong());
    break;
  default:
    return C_UNDEFINED;
  }
};

C_INSTRUCTION_DEST stringToDestEnum(std::string dest) {
  if (dest == "")
    return DEST_NULL;
  if (dest == "M")
    return DEST_M;
  if (dest == "D")
    return DEST_D;
  if (dest == "MD")
    return DEST_MD;
  if (dest == "A")
    return DEST_A;
  if (dest == "AM")
    return DEST_AM;
  if (dest == "AD")
    return DEST_AD;
  if (dest == "AMD")
    return DEST_AMD;
  return DEST_UNDEFINED;
};
C_INSTRUCTION_COMP stringToCompEnum(std::string comp) {
  if (comp == "0")
    return COMP_ZERO;
  if (comp == "1")
    return COMP_ONE;
  if (comp == "-1")
    return COMP_MINUS_ONE;
  if (comp == "D")
    return COMP_D;
  if (comp == "A")
    return COMP_A;
  if (comp == "M")
    return COMP_M;
  if (comp == "!D")
    return COMP_NOT_D;
  if (comp == "!A")
    return COMP_NOT_A;
  if (comp == "!M")
    return COMP_NOT_M;
  if (comp == "-D")
    return COMP_MINUS_D;
  if (comp == "-A")
    return COMP_MINUS_A;
  if (comp == "-M")
    return COMP_MINUS_M;
  if (comp == "D+1")
    return COMP_D_PLUS_ONE;
  if (comp == "A+1")
    return COMP_A_PLUS_ONE;
  if (comp == "M+1")
    return COMP_M_PLUS_ONE;
  if (comp == "D-1")
    return COMP_D_MINUS_ONE;
  if (comp == "A-1")
    return COMP_A_MINUS_ONE;
  if (comp == "M-1")
    return COMP_M_MINUS_ONE;
  if (comp == "D+A")
    return COMP_D_PLUS_A;
  if (comp == "D+M")
    return COMP_D_PLUS_M;
  if (comp == "D-A")
    return COMP_D_MINUS_A;
  if (comp == "D-M")
    return COMP_D_MINUS_M;
  if (comp == "A-D")
    return COMP_A_MINUS_D;
  if (comp == "M-D")
    return COMP_M_MINUS_D;
  if (comp == "D&A")
    return COMP_D_ASP_A;
  if (comp == "D&M")
    return COMP_D_ASP_M;
  if (comp == "D|A")
    return COMP_D_PIPE_A;
  if (comp == "D|M")
    return COMP_D_PIPE_M;
  return COMP_UNDEFINED;
};
C_INSTRUCTION_JUMP stringToJumpEnum(std::string jump) {
  if (jump == "")
    return JUMP_NULL;
  if (jump == "JGT")
    return JUMP_JGT;
  if (jump == "JEQ")
    return JUMP_JEQ;
  if (jump == "JGE")
    return JUMP_JGE;
  if (jump == "JLTJ")
    return JUMP_JLT;
  if (jump == "JNE")
    return JUMP_JNE;
  if (jump == "JLE")
    return JUMP_JLE;
  if (jump == "JMP")
    return JUMP_JMP;
  return JUMP_UNDEFINED;
};
