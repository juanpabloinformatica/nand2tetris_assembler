#ifndef __PARSER__
#define __PARSER__
#include "../include/Utilities.hpp"
#include <string>
class Code {
private:
  std::string destBinary;
  std::string compBinary;
  std::string jumpBinary;
  std::string binaryInstruction;

public:
  // std::bitset<DEST_BITS_LENGTH> dest(std::string currentDest);
  // std::bitset<COMP_BITS_LENGTH> comp(std::string currentComp);
  // std::bitset<JUMP_BITS_LENGTH> jump(std::string currentJump);
  // std::string dest(std::string currentDest);
  // std::string comp(std::string currentComp);
  // std::string jump(std::string currentJump);
  void setDestBinary(std::string currentDest);
  void setCompBinary(std::string currentComp);
  void setJumpBinary(std::string currentJump);
  void setBinaryInstruction(void);
};
#endif
