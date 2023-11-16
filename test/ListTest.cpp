#include "../include/List.h"
#include <iostream>

void printList(List<int>* lst) {
   for (int i = 0; i < lst->Count(); ++i) {
      std::cout << lst->GetAt(i) << " ";
   }
   std::cout << std::endl;
}

int main() {
   List<int>* lista = new List<int>;
   for (int i = 0; i < 5; ++i) {
      lista->Add(i);
   }
   std::cout << "T0: Count() = " << lista->Count() << std::endl;
   if (lista->Count() != 5) {
      return 1;
   }
   std::cout << "T1: Add" << std::endl;
   printList(lista);
   for (int i = 0; i < 5; ++i) {
      if (lista->GetAt(i) != i) {
	 return 1;
      }
   }
   lista->RemoveAt(0);
   lista->RemoveAt(2);
   std::cout << "T2: RemoveAt" << std::endl;
   printList(lista);
   if (lista->GetAt(0) != 1 && lista->GetAt(1) != 2 && lista->GetAt(3) != 4) {
      return 1;
   }
   lista->SetAt(1, 4);
   std::cout << "T3: SetAt" << std::endl;
   printList(lista);
   if (lista->GetAt(1) != 4) {
      return 1;
   }
   std::cout << "T4: IndexOf() = " << lista->IndexOf(4) << std::endl;
   if (lista->IndexOf(4) != 1) {
      return 1;
   }
   return 0;
}
