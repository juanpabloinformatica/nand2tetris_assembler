#include "../include/TestCode.hpp"
void testingCode(void) {
  // "D=A", "M=D", "D=D-M", "M=M+D", "D;JLE"
  // Parser
  Parser parser = Parser("");
  Code code = Code();
  const int testArrayLength = 5;
  std::string testArray[testArrayLength] = {"D=A", "M=D", "D=D-M", "M=M+D",
                                            "D;JLE"};
  parser.setDest(testArray[0]);
  parser.setComp(testArray[0]);
  parser.setJump(testArray[0]);
}
