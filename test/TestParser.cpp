#include "TestParser.hpp"
#include <cassert>
void testingParser(void) {
  Parser parser = Parser();
  const int testArrayLength = 5;
  std::string testArray[testArrayLength] = {"D=A", "M=D", "D=D-M", "M=M+D",
                                            "D;JLE"};
  parser.setDest(testArray[0]);
  parser.setComp(testArray[0]);
  parser.setJump(testArray[0]);
  assert(parser.getDest() == "D");
  assert(parser.getComp() == "A");
  assert(parser.getJump() == "");
  parser.resetParser();
  parser.setDest(testArray[1]);
  parser.setComp(testArray[1]);
  parser.setJump(testArray[1]);
  assert(parser.getDest() == "M");
  assert(parser.getComp() == "D");
  assert(parser.getJump() == "");
  parser.resetParser();
  parser.setDest(testArray[2]);
  parser.setComp(testArray[2]);
  parser.setJump(testArray[2]);
  assert(parser.getDest() == "D");
  assert(parser.getComp() == "D-M");
  assert(parser.getJump() == "");
  parser.resetParser();
  parser.setDest(testArray[3]);
  parser.setComp(testArray[3]);
  parser.setJump(testArray[3]);
  assert(parser.getDest() == "M");
  assert(parser.getComp() == "M+D");
  assert(parser.getJump() == "");
  parser.resetParser();
  parser.setDest(testArray[4]);
  parser.setComp(testArray[4]);
  parser.setJump(testArray[4]);
  assert(parser.getDest() == "");
  assert(parser.getComp() == "D");
  assert(parser.getJump() == "JLE");
  parser.resetParser();
}
