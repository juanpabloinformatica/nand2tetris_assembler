#ifndef __SYMBOL_TABLE__
#define __SYMBOL_TABLE__
#include <iostream>
#include <map>
#include <string>
class SymbolTable {
public:
  std::map<std::string, int> symbolTable;
  int romAddress;
  int variablesCounter;
  SymbolTable();
  void setSymbolTable(void);
  void addEntry(std::string symbol, int romAddress);
  bool contains(std::string symbol);
  int getRomAddress(std::string symbol);
  void printSymbolTable(void);
};
#endif
