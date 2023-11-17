#pragma once
#include <string>

class Hash {
  public:
   static char* Hashing(std::string Key, int numIter = 1); // Estático por que no necesitamos crearlo como objeto.
};
