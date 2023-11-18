#include "../include/Hash.h"

std::string Hash::Hashing(std::string Key, int numIter) {
   std::string output = "";
   for (int j = 0; j < 10; ++j) {
      output += Key[j] ^ 0x55 - 0x4848FAFA * numIter + numIter^3^9;
      output = output.substr(0, j + 1);
   }
   return output.substr(0, 10);
}
