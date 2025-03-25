#ifndef __PARSER__
#define __PARSER__
#include "../include/Utilities.hpp"
#include <string>
class Code {
public:
  // std::bitset<DEST_BITS_LENGTH> dest(std::string currentDest);
  // std::bitset<COMP_BITS_LENGTH> comp(std::string currentComp);
  // std::bitset<JUMP_BITS_LENGTH> jump(std::string currentJump);
  std::string dest(std::string currentDest);
  std::string comp(std::string currentComp);
  std::string jump(std::string currentJump);
};
#endif
