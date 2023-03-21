#include <string>
#include "../include/Decoder.h"

auto Decoder::upperCase(const std::string &cipherText) -> bool {
  if (!cipherText.empty()) {
    for (char i : cipherText) {
      if (isupper(i))
        return true;
      else
        return false;
    }
  }

  return true;
}

auto Decoder::decryptCaesarShift(const std::string &cipherText) -> std::string {
  std::string plainText;
  char ascii;
  int key = 25;

  if (upperCase(cipherText))
    ascii = 'A';
  else
    ascii = 'a';

  for (char c : cipherText) {
    if (isalpha(c)) {
      c = (c - ascii + 26 - key) % 26 + ascii;
    }
    plainText += c;
  }

  return plainText;
}
