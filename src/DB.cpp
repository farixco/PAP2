#include "../include/DB.h"
#include "../include/Hash.h"
#include <fstream>

void DB::Sort() {
   for (int i = 0; i < Length; ++i) {
      for (int j = 0; j < Length; ++j) {
	 if (this->GetAt(i)[0] < this->GetAt(j)[0]) {
	    std::string* tmp = this->GetAt(i);
	    this->SetAt(i, this->GetAt(j));
	    this->SetAt(j, tmp);
	 }
      }
   }
}

void DB::Load(std::string filepath) {
   std::string line;
   std::ifstream file(filepath);
   if (file.is_open() && readline == 0) {
      while(std::getline(file, line)) {
	 readline++;
      }
   }
   std::ifstream file2(filepath);
   if (file2.is_open()) {
      while(std::getline(file2, line)) {
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
	    if (i != 4) {
	       line.erase(0, posTmp + 1);
	    }
	 }
	 data[4] = line.substr(0,posTmp);
	 Add(data);
      }
   }
}

List<int>* DB::SearchK(std::string Key) {
   std::string hK = Hash::Hashing(Key, readline);
   Node* izq = Head;
   Node* der = Tail;
   int i = 0, j = Length;
   List<int>* tmp = new List<int>;
   while (izq && der && izq != der && izq->Next != der) {
      if (izq->Data[0] == Key) {
	 tmp->Add(i);
      }
      if (der->Data[0] == Key) {
	 tmp->Add(j);
      }
      izq = izq->Next;
      ++i;
      der = der->Prev;
      --j;
   }
   return tmp;
}

List<int>* DB::SearchV(std::string Value) {
   List<int>* tmp = new List<int>;
   Node* bncr = Head;
   int i = 0;
   while (bncr) {
      for (int j = 1; j < 4; ++j) {
	 if (bncr->Data[j] == Value) {
	    tmp->Add(i);
	 }
      }
      bncr = bncr->Next;
      ++i;
   }
   return tmp;
}
