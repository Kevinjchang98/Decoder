//
// Created by Kevin Chang on 2/5/23.
//

#ifndef DECODER__DECODER_H_
#define DECODER__DECODER_H_

#include <string>

class Decoder {
 public:
  auto static decryptCaesarShift(const std::string &cipherText) -> std::string;
  auto static upperCase(const std::string &cipherText) -> bool;
};

#endif //DECODER__DECODER_H_
