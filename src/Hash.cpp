#include "../include/Hash.h"

char* Hash::Hashing(std::string Key, int numIter) {
   char output[11] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
   for (int i = 0; i < numIter; ++i) {
      for (int j = 0; j < 10; ++j) {
	 output[j] = Key[j] ^ 0x55; // Método XOR con una constante arbitraria
      }
   }
   return output;
}
