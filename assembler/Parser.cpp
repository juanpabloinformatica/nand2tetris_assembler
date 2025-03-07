#include "Parser.hpp"
#include <fstream>

Parser::Parser(std::string filepath) {
  std::cout << "Entering here" <<std::endl;
  this->file = std::fstream(filepath);
  // std::cout<<this->file
  std::string text;
  while (std::getline(this->file, text)) {
    std::cout << text << std::endl;
  }
}

// #ifndef __VOITURE
// #define __VOITURE
// #include <iostream>
// class Voiture {
// public:
//   std::string band;
//   std::string model;
//   int year;
//   std::string show(void);
//   Voiture(std::string band, std::string model, int year);
// };
//
// #endif
// #include "Voiture.hpp"
// #include <iostream>
// using namespace std;
// string Voiture::show() {
//   return "band: " + this->band + "\nmodel: " + this->model +
//          "\nyear: " + to_string(this->year);
// };
// Voiture::Voiture(std::string band, std::string model, int year) {
//   this->band = band;
//   this->model = model;
//   this->year = year;
// };
