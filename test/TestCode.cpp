#include "TestCode.hpp"
void testingCode(void) {
  // "D=A", "M=D", "D=D-M", "M=M+D", "D;JLE"
  // Parser
  Code code = Code();
  Parser parser = Parser();
  const int testArrayLength = 10;
  std::string testArray[testArrayLength] = {"D=A",   "M=D",   "D=D-M", "M=D+M",
                                            "D;JLE", "0;JMP", "@0",    "@2",
                                            "@30",   "@17"};
  /*
   *  ---- c_ins
   * 1110110000010000 -> D=A
   * 1110001100001000 -> M=D
   * 1111010011010000 -> D=D-M
   * 1111000010001000 -> M=D+M
   * 1110001100000110 -> D;JLE
   * 1110101010000111 -> 0;JMP
   * ____ a_inst
   * 0000000000000000 -> @0
   * 0000000000000010 -> @2
   * 0000000000011110 -> @30
   * 0000000000010001 -> @17
   * */
  // * 1110110000010000 -> D=A
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
  assert(code.getBinaryInstruction() == "1110110000010000");
  parser.resetParser();

  // * 1110001100001000 -> M=D
  parser.setDest(testArray[1]);
  parser.setComp(testArray[1]);
  parser.setJump(testArray[1]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "001");
  assert(code.getCompBinary() == "0001100");
  assert(code.getJumpBinary() == "000");
  assert(code.getBinaryInstruction() == "1110001100001000");
  parser.resetParser();
  // * 1111010011010000 -> D=D-M
  parser.setDest(testArray[2]);
  parser.setComp(testArray[2]);
  parser.setJump(testArray[2]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "010");
  assert(code.getCompBinary() == "1010011");
  assert(code.getJumpBinary() == "000");
  assert(code.getBinaryInstruction() == "1111010011010000");
  parser.resetParser();
  // * 1111000010001000 -> M=D+M
  parser.setDest(testArray[3]);
  parser.setComp(testArray[3]);
  parser.setJump(testArray[3]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "001");
  assert(code.getCompBinary() == "1000010");
  assert(code.getJumpBinary() == "000");
  assert(code.getBinaryInstruction() == "1111000010001000");
  parser.resetParser();
  // * 1110001100000110 -> D;JLE
  // 1110001100000110
  parser.setDest(testArray[4]);
  parser.setComp(testArray[4]);
  parser.setJump(testArray[4]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "000");
  assert(code.getCompBinary() == "0001100");
  assert(code.getJumpBinary() == "110");
  assert(code.getBinaryInstruction() == "1110001100000110");
  parser.resetParser();
  // * 1110101010000111 -> 0;JMP
  parser.setDest(testArray[5]);
  parser.setComp(testArray[5]);
  parser.setJump(testArray[5]);
  code.setDestBinary(parser.getDest());
  code.setCompBinary(parser.getComp());
  code.setJumpBinary(parser.getJump());
  code.setBinaryInstruction(C_COMMAND);
  assert(code.getDestBinary() == "000");
  assert(code.getCompBinary() == "0101010");
  assert(code.getJumpBinary() == "111");
  assert(code.getBinaryInstruction() == "1110101010000111");
  parser.resetParser();
  // * 0000000000000000 -> @0
  parser.setSymbol(testArray[6]);
  assert(parser.getSymbol() == "0");
  code.setBinaryValue(parser.getSymbol());
  code.setBinaryInstruction(A_COMMAND);
  assert(parser.getSymbol() == "0");
  assert(code.getBinaryInstruction() == "0000000000000000");
  parser.resetParser();
  // * 0000000000000010 -> @2
  parser.setSymbol(testArray[7]);
  assert(parser.getSymbol() == "2");
  code.setBinaryValue(parser.getSymbol());
  code.setBinaryInstruction(A_COMMAND);
  // assert(code.getBinaryInstruction() == "0000000000000010");
  parser.resetParser();
  // * 0000000000011110 -> @30
  parser.setSymbol(testArray[8]);
  assert(parser.getSymbol() == "30");
  code.setBinaryValue(parser.getSymbol());
  code.setBinaryInstruction(A_COMMAND);
  assert(code.getBinaryInstruction() == "0000000000011110");
  parser.resetParser();
  // * 0000000000010001 -> @17
}
