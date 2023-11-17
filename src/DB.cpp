#include "../include/DB.h"
#include "../include/Hash.h"
#include <fstream>

void DB::ISort() {
   if (!Head || !Head->Next) {
      return;
   }
   Node* srtAct = nullptr;
   Node* placeholder = Head;

   while (placeholder) {
      Node* next = placeholder->Next;

      if (!srtAct || srtAct->Data >= placeholder->Data) {
	 placeholder->Next = srtAct;
	 placeholder->Prev = nullptr;
	 srtAct->Prev = placeholder;
	 srtAct = placeholder;
      } else {
	 Node* temp = srtAct;
	 while (temp->Next && temp->Next->Data < placeholder->Data) {
	    temp = temp->Next;
	 }
	 placeholder->Next = temp->Next;
	 placeholder->Prev = temp;
	 if (temp->Next) {
	    temp->Next->Prev = placeholder;
	 }
	 temp->Next = placeholder;
      }

      placeholder = next;
   }
   Head = srtAct;
   Tail = srtAct;
   while (Tail->Next) {
      Tail = Tail->Next;
   }
}

void DB::Load(std::string filepath) {
   std::string line;
   std::ifstream file(filepath);
   int readline = 0;
   if (file.is_open()) {
      while(std::getline(file, line)) {
	 readline++;
      }
   }
   if (file.is_open()) {
      while(std::getline(file, line)) {
	 int posTmp = 0;
	 int i = 0;
	 std::string data[5];
	 while ((posTmp = line.find(',')) != std::string::npos) {
	    if (i == 0) {
	       data[i] = Hash::Hashing(line.substr(0,posTmp), readline);
	    } else {
	       data[i] = line.substr(0,posTmp);
	    }
	    ++i;
	    line.erase(0, posTmp + 1);
	 }
	 Add(data);
      }
   }
}
