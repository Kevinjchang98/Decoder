//
// Created by Kevin Chang on 2/5/23.
//

#ifndef DECODER__DECODER_H_
#define DECODER__DECODER_H_

#include <string>

class Decoder {
 public:
  auto static decryptCaesarShift(const std::string& text) -> std::string;

    static bool upperCase(const std::string& cipher_text);

    bool is_all_upper(const std::string &cipher_text);
};

#endif //DECODER__DECODER_H_
