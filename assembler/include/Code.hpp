#ifndef __CODE__
#define __CODE__
#include "../include/Utilities.hpp"
#include <string>
class Code {
private:
  std::string destBinary;
  std::string compBinary;
  std::string jumpBinary;
  std::string binaryInstruction;

public:
  Code();
  void setDestBinary(std::string currentDest);
  void setCompBinary(std::string currentComp);
  void setJumpBinary(std::string currentJump);
  void setBinaryInstruction(COMMAND_TYPE type);
  std::string getDestBinary(void);
  std::string getCompBinary(void);
  std::string getJumpBinary(void);
  std::string getBinaryInstruction(void);

};
#endif
