#include "../include/TestCode.hpp"
void testingCode(void) {
  // "D=A", "M=D", "D=D-M", "M=M+D", "D;JLE"
  // Parser
  Code code = Code();
  Parser parser = Parser("");
  const int testArrayLength = 5;
  std::string testArray[testArrayLength] = {"D=A", "M=D", "D=D-M", "M=M+D",
                                            "D;JLE"};
  parser.setDest(testArray[0]);
  parser.setComp(testArray[0]);
  parser.setJump(testArray[0]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "010");
  assert(code.getCompBinary() == "0110000");
  assert(code.getJumpBinary() == "000");
  assert(code.getDestBinary() == "1110100110000000");

  parser.resetParser();
}
