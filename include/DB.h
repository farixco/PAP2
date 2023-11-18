#pragma once
#include "List.h"

class DB : protected List<std::string*> {
  private:
   void ISort();
   int readline = 0;
  public:
   void Load(std::string filepath);
   int* SearchK(std::string Key);
   int* SearchV(std::string Value);
};
