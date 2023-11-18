#pragma once
#include "List.h"

class DB : protected List<std::string*> {
  private:
   int readline = 0;
   void Sort();
  public:
   using List<std::string*>::Count;
   using List<std::string*>::GetAt;
   void Load(std::string filepath);
   List<int>* SearchK(std::string Key);
   List<int>* SearchV(std::string Value);
};
