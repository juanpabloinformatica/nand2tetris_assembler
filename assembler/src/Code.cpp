#include "../include/Code.hpp"

std::string Code::dest(std::string currentDest) {
  C_INSTRUCTION_DEST destEnum = stringToDestEnum(currentDest);
  return std::bitset<DEST_BITS_LENGTH>(destEnum).to_string();
}
std::string Code::comp(std::string currentComp) {
  C_INSTRUCTION_COMP compEnum = stringToCompEnum(currentComp);
  return std::bitset<DEST_BITS_LENGTH>(compEnum).to_string();
}
std::string Code::jump(std::string currentJump) {
  C_INSTRUCTION_JUMP jumpEnum = stringToJumpEnum(currentJump);
  return std::bitset<JUMP_BITS_LENGTH>(jumpEnum).to_string();
}
