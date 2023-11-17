#pragma once
#include "List.h"

class DB : protected List<std::string*> {
  private:
   void ISort();
  public:
   void Load(std::string filepath);
   std::string* Search(std::string hKey);
};
