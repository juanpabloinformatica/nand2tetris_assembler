#ifndef __UTILITIES__
#define __UTILITIES__
#include <bitset>
#include <filesystem>
#include <fstream>
#include <regex>
#include <string>
#define C_INSTRUCTION_PREFIX "111"
#define A_INSTRUCTION_PREFIX "0"
#define DEST_BITS_LENGTH 3
#define JUMP_BITS_LENGTH 3
#define COMP_BITS_LENGTH 7
#define A_BINARY_VALUE_LENGTH 15
enum C_INSTRUCTION_SECTION {
  C_UNDEFINED = -1,
  C_DEST = 0,
  C_COMP = 1,
  C_JUMP = 2
};
enum COMMAND_TYPE { A_COMMAND, L_COMMAND, C_COMMAND };
enum INSTRUCTION_BITS {
  INS_UNDEFINED = -1,
  INS_OP_CODE = 0,
  INS_DEFAULT_1 = 1,
  INS_DEFAULT_2 = 2,
  INS_A_VALUE = 3,
  INS_C1 = 4,
  INS_C2 = 5,
  INS_C3 = 6,
  INS_C4 = 7,
  INS_C5 = 8,
  INS_C6 = 9,
  INS_D1 = 10,
  INS_D2 = 11,
  INS_D3 = 12,
  INS_J1 = 13,
  INS_J2 = 14,
  INS_J3 = 15
};
enum C_INSTRUCTION_DEST {
  DEST_UNDEFINED = -1,
  DEST_NULL = 0,
  DEST_M = 1,
  DEST_D = 2,
  DEST_MD = 3,
  DEST_A = 4,
  DEST_AM = 5,
  DEST_AD = 6,
  DEST_AMD = 7
};
enum C_INSTRUCTION_COMP {
  COMP_UNDEFINED = -1,
  COMP_ZERO = 42,
  COMP_ONE = 63,
  COMP_MINUS_ONE = 58,
  COMP_D = 12,
  COMP_A = 48,
  COMP_M = 112,
  COMP_NOT_D = 13,
  COMP_NOT_A = 49,
  COMP_NOT_M = 113,
  COMP_MINUS_D = 15,
  COMP_MINUS_A = 51,
  COMP_MINUS_M = 115,
  COMP_D_PLUS_ONE = 31,
  COMP_A_PLUS_ONE = 55,
  COMP_M_PLUS_ONE = 119,
  COMP_D_MINUS_ONE = 14,
  COMP_A_MINUS_ONE = 50,
  COMP_M_MINUS_ONE = 114,
  COMP_D_PLUS_A = 2,
  COMP_D_PLUS_M = 66,
  COMP_D_MINUS_A = 19,
  COMP_D_MINUS_M = 83,
  COMP_A_MINUS_D = 7,
  COMP_M_MINUS_D = 71,
  COMP_D_ASP_A = 0,
  COMP_D_ASP_M = 64,
  COMP_D_PIPE_A = 21,
  COMP_D_PIPE_M = 85
};
enum C_INSTRUCTION_JUMP {
  JUMP_UNDEFINED = -1,
  JUMP_NULL = 0,
  JUMP_JGT = 1,
  JUMP_JEQ = 2,
  JUMP_JGE = 3,
  JUMP_JLT = 4,
  JUMP_JNE = 5,
  JUMP_JLE = 6,
  JUMP_JMP = 7,
};
unsigned long int bitsToULong(std::string instructionString,
                              C_INSTRUCTION_SECTION section, int initPos);
C_INSTRUCTION_DEST stringToDestEnum(std::string dest);
C_INSTRUCTION_COMP stringToCompEnum(std::string comp);
C_INSTRUCTION_JUMP stringToJumpEnum(std::string jump);

std::string getFilepath(std::string file);
// taken from stack overflow
bool isNumber(std::string stringNumber);

#endif
