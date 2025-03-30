#include "SymbolTable.hpp"
SymbolTable::SymbolTable(void) {
  this->romAddress = 0;
  this->variablesCounter = 16;
  setSymbolTable();
}
void SymbolTable::setSymbolTable() {
  this->symbolTable["SP"] = 0;
  this->symbolTable["LCL"] = 1;
  this->symbolTable["ARG"] = 2;
  this->symbolTable["THIS"] = 3;
  this->symbolTable["THAT"] = 4;
  this->symbolTable["R0"] = 0;
  this->symbolTable["R1"] = 1;
  this->symbolTable["R2"] = 2;
  this->symbolTable["R3"] = 3;
  this->symbolTable["R4"] = 4;
  this->symbolTable["R5"] = 5;
  this->symbolTable["R6"] = 6;
  this->symbolTable["R7"] = 7;
  this->symbolTable["R8"] = 8;
  this->symbolTable["R9"] = 9;
  this->symbolTable["R10"] = 10;
  this->symbolTable["R11"] = 11;
  this->symbolTable["R12"] = 12;
  this->symbolTable["R13"] = 13;
  this->symbolTable["R14"] = 14;
  this->symbolTable["R15"] = 15;
  this->symbolTable["SCREEN"] = 16384;
  this->symbolTable["KBD"] = 24576;
}
void SymbolTable::addEntry(std::string symbol, int romAddress) {
  this->symbolTable[symbol] = romAddress;
}
bool SymbolTable::contains(std::string symbol) {
  return this->symbolTable.contains(symbol);
}
int SymbolTable::getRomAddress(std::string symbol) {
  return this->symbolTable.at(symbol);
}
void SymbolTable::printSymbolTable() {
  // why that & ?? why the reference to study
  for (const auto &[key, value] : this->symbolTable) {
    std::cout << '[' << key << "] = " << value << std::endl;
  }
}
