#include "../include/TestParser.hpp"
#include <cassert>
typedef struct ParserTester ParserTester;
struct ParserTester {
  std::string dest;
  std::string comp;
  std::string jump;
};
void testingParser() {
  ParserTester parserTesterArray[5];
  std::string testArray[5] = {"D=A", "M=D", "D=D-M", "M=M+D", "D;JLE"};
  Parser parser = Parser("");
  int *ptrIndexCurrentCommand;
  int indexCurrentCommand = 0;
  ptrIndexCurrentCommand = &indexCurrentCommand;
  parserTesterArray[0].dest =
      parser.getDest(ptrIndexCurrentCommand, testArray[0]);
  parserTesterArray[0].comp =
      parser.getComp(ptrIndexCurrentCommand, testArray[0]);
  parserTesterArray[0].jump =
      parser.getJump(ptrIndexCurrentCommand, testArray[0]);
  assert(parserTesterArray[0].dest == "D");
  assert(parserTesterArray[0].comp == "A");
  assert(parserTesterArray[0].jump == "");

  indexCurrentCommand = 0;
  parserTesterArray[1].dest =
      parser.getDest(ptrIndexCurrentCommand, testArray[1]);
  parserTesterArray[1].comp =
      parser.getComp(ptrIndexCurrentCommand, testArray[1]);
  parserTesterArray[1].jump =
      parser.getJump(ptrIndexCurrentCommand, testArray[1]);
  assert(parserTesterArray[1].dest == "M");
  assert(parserTesterArray[1].comp == "D");
  assert(parserTesterArray[1].jump == "");

  indexCurrentCommand = 0;
  parserTesterArray[2].dest =
      parser.getDest(ptrIndexCurrentCommand, testArray[2]);
  parserTesterArray[2].comp =
      parser.getComp(ptrIndexCurrentCommand, testArray[2]);
  parserTesterArray[2].jump =
      parser.getJump(ptrIndexCurrentCommand, testArray[2]);
  assert(parserTesterArray[2].dest == "D");
  assert(parserTesterArray[2].comp == "D-M");
  assert(parserTesterArray[2].jump == "");

  indexCurrentCommand = 0;
  parserTesterArray[3].dest =
      parser.getDest(ptrIndexCurrentCommand, testArray[3]);
  parserTesterArray[3].comp =
      parser.getComp(ptrIndexCurrentCommand, testArray[3]);
  parserTesterArray[3].jump =
      parser.getJump(ptrIndexCurrentCommand, testArray[3]);
  assert(parserTesterArray[3].dest == "M");
  assert(parserTesterArray[3].comp == "M+D");
  assert(parserTesterArray[3].jump == "");

  indexCurrentCommand = 0;
  parserTesterArray[4].dest =
      parser.getDest(ptrIndexCurrentCommand, testArray[4]);
  parserTesterArray[4].comp =
      parser.getComp(ptrIndexCurrentCommand, testArray[4]);
  parserTesterArray[4].jump =
      parser.getJump(ptrIndexCurrentCommand, testArray[4]);
  assert(parserTesterArray[4].dest == "");
  assert(parserTesterArray[4].comp == "D");
  assert(parserTesterArray[4].jump == "JLE");
}

