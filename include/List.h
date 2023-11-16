#pragma once
#include <stdexcept>
/* Por ser template, se incluyen las definiciones en el mismo
 * header para que el linker no se muera.
 */
template <typename T>
class List {
  protected:
   struct Node {
      Node* Next = nullptr;
      T Data;
   };
   Node* Head = nullptr;
   Node* Tail = nullptr;
   int Length = 0;
  public:
   void Add(T item) {
      if (Head == nullptr) {
	 Head = new Node;
	 Head->Data = item;
	 Tail = Head;
	 ++Length;
      } else {
	 Node* Placeholder = new Node;
	 Placeholder->Data = item;
	 Placeholder->Next = nullptr;
	 Tail->Next = Placeholder;
	 Tail = Placeholder;
	 ++Length;
      }
   }
   
   void RemoveAt(int index) {
   if (index < Length && index >= 0) {
      if (index > 0) {
	 Node* placeholder = Head;
	 for (int i = 0; i < index - 1; ++i) {
	    placeholder = placeholder->Next;
	 }
	 Node* p2 = placeholder->Next->Next;
	 delete placeholder->Next;
	 placeholder->Next = p2;
      } else {
	 Head = Head->Next;
      }
      --Length;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}
      
   T GetAt (int index)  {
   if (index < Length && index >= 0) {
      Node* placeholder = Head;
      for (int i = 0; i < index; ++i) {
	 placeholder = placeholder->Next;
      }
      return placeholder->Data;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}
      
   void SetAt(int index, T item) {
   if (index < Length && index >= 0) {
      Node* placeholder = Head;
      for (int i = 0; i < index; ++i) {
	 placeholder = placeholder->Next;
      }
      placeholder->Data = item;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}
      
   int IndexOf(T item)  {
   Node* placeholder = Head;
   for (int i = 0; i < Length; ++i) {
      if (placeholder->Data == item) {
	 return i;
      } else {
	 placeholder = placeholder->Next;
      }
   }
   return -1;
}
      
   int Count() {
   return Length;
}
};
