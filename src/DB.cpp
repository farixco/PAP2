#include "../include/DB.h"
#include "../include/Hash.h"
#include <fstream>

DB::Node* DB::Part(Node* p, Node* s) {
   std::string* tmp = s->Data;
   Node* t1 = p->Prev;
   for (Node* t2 = p; t2 != s; t2 = t2->Next) {
      if (t2->Data[0] <= tmp[0]) {
	 if (t1 == nullptr) {
	    t1 = p;
	 } else {
	    t1 = t1->Next;
	 }
      }
   }
   if (t1 == nullptr) {
      t1 = p;
   } else {
      t1 = t1->Next;
   }
   s->Data = t1->Data;
   t1->Data = tmp;
   return t1;
}

void DB::QSort(Node* p, Node* s) {
   if (s != nullptr && p != s && p != s->Next) {
      Node* tmp = Part(p, s);
      QSort(p, tmp->Prev);
      QSort(tmp->Next, s);
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
	 std::string* data = new std::string[5];
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
   QSort(Head, Tail);
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
