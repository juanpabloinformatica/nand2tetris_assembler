#include "../include/TestParser.hpp"
#include <cassert>
void testingParser() {
  // Parser parser = Parser("");
  // // dest,comp,jump
  //
  // // 1110110000010000
  // // dest = 010 = D
  // // comp = 0110000 = A
  // // jump = 000 = null
  // // M=A;
  // int i1Dest = parser.getDest("1110110000010000");
  // int i1Comp = parser.getComp("1110110000010000");
  // int i1Jump = parser.getJump("1110110000010000");
  // assert(i1Dest == 2);
  // assert(i1Comp == 48);
  // assert(i1Jump == 0);
  // std::cout << "First access working" <<std::endl;
  // // 1110001100001000
  // //Dest == 001 ==> M
  // //comp == 0001100 ==> D
  // //jump == 000 ==> null
  // int i2Dest = parser.getDest("1110001100001000");
  // int i2Comp = parser.getComp("1110001100001000");
  // int i2Jump = parser.getJump("1110001100001000");
  // assert(i2Dest == 1);
  // assert(i2Comp == 12);
  // assert(i2Jump == 0);
  // std::cout << "second access working" <<std::endl;
  // // 1110110000010000
  // // 1110001100001000
  // // 1111110000010000
}
void testParserDest() {
  std::string arrT[3] = {"D=", "AD=", "COMP;JUMP"};
  std::string arrR[3];
  Parser parser = Parser("");
  // This will be reinitialized each time the
  // while will run again
  int *ptrIndexCurrentCommand;
  int indexCurrentCommand = 0;
  ptrIndexCurrentCommand = &indexCurrentCommand;
  // -----------
  arrR[0] = parser.getDest(ptrIndexCurrentCommand, arrT[0]);
  arrR[1] = parser.getDest(ptrIndexCurrentCommand, arrT[1]);
  arrR[2] = parser.getDest(ptrIndexCurrentCommand, arrT[2]);
  assert(arrR[0] == "D");
  assert(arrR[1] == "AD");
  assert(arrR[2] == "");
}
void testParserComp() {
  std::string arrT[4] = {"D=0;", "0;JMP", "COMP;JUMP", "D-A;"};
  std::string arrR[4];
  Parser parser = Parser("");
  int *ptrIndexCurrentCommand;
  int indexCurrentCommand = 0;
  ptrIndexCurrentCommand = &indexCurrentCommand;
  arrR[0] = parser.getComp( ptrIndexCurrentCommand ,arrT[0] );
  // arrR[1] = parser.getComp( ptrIndexCurrentCommand ,arrT[1] );
  // arrR[2] = parser.getComp( ptrIndexCurrentCommand ,arrT[2] );
  // arrR[3] = parser.getComp( ptrIndexCurrentCommand ,arrT[3] );
  assert(arrR[0] == "0");
  assert(arrR[1] == "0");
  assert(arrR[2] == "COMP");
  assert(arrR[3] == "D-A");
}
