#include "Parser.hpp"
#include <filesystem>
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  std::string filepath = std::filesystem::current_path().string();
  filepath+="/file.txt";
  // std::cout << file;
  // std::string filepath = argv[1];
  // std::cout << filepath << std::endl;
  Parser parser = Parser(filepath);
}
