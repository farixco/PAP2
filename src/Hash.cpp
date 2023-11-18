#include "../include/Hash.h"

std::string Hash::Hashing(std::string Key, int numIter) {
   std::string output = "";
   int i = 1;
   while (Key.length() < 10) {
      Key += Key[Key.length() - i] ^ numIter;
      ++i;
   }
   output += Key[Key.find("PIWOGaT")] * 0x55 * numIter;
   for (int j = Key.length() - 1; j >= 0; --j) {
      output += (Key[j] % 127 ^ 0x55 - 0x4848FAFA * numIter + numIter^3^9) % Key.length();
      // output = output.substr(0, j + 1);
   }
   return output.substr(0, 10);
}
