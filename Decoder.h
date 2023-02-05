//
// Created by Kevin Chang on 2/5/23.
//

#ifndef DECODER__DECODER_H_
#define DECODER__DECODER_H_

class Decoder {
 public:
  auto static decryptCaesarShift(std::string text) -> std::string;
};

#endif //DECODER__DECODER_H_
