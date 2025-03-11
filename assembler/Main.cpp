#include "Parser.hpp"
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  std::string filepath = std::filesystem::current_path().string();
  filepath += "/file.txt";
  // std::cout << file;
  // std::string filepath = argv[1];
  // std::cout << filepath << std::endl;
  Parser parser = Parser(filepath);
  // std::cout << parser.getCommandType("@aa") << std::endl;
  std::cout << parser.getSymbol("@aaaaaaa") << std::endl;
  // std::cout << parser.getCommandType("@1") << std::endl;
  std::cout << parser.getSymbol("@122222") << std::endl;
  // std::cout << parser.getCommandType("(xxx)") << std::endl;
  std::cout << parser.getSymbol("(xxjaha;ejfa;fasx)") << std::endl;
  // std::cout << parser.getCommandType("1") << std::endl;
  // std::cout << parser.getCommandType("(xxx)") << std::endl;
  // std::cout << parser.getCommandType("()") << std::endl;

  //010 ==> D
  std::cout << parser.getDest("1111110000010000") << std::endl;
  std::cout << "Instruction: " << std::endl;
  //000 ==> null
  std::cout << parser.getDest("1110001100000010") << std::endl;
  std::cout << "Instruction: " << std::endl;
  //010 ==> D
  std::cout << parser.getDest("1110110000010000") << std::endl;
  std::cout << "Instruction: " << std::endl;
  //001 == M
  std::cout << parser.getDest("1111110111001000") << std::endl;

}
