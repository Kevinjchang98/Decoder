#include <string>
#include "../include/Decoder.h"

bool Decoder::upperCase(const std::string& cipher_text) {
    if (!cipher_text.empty()) {
        for (char i : cipher_text) {
            if (isupper(i))
                return true;
            else
                return false;
        }
    }
    return true;
}

auto Decoder::decryptCaesarShift(const std::string& cipher_text) -> std::string {
    std::string plain_text;
    char ascii;
    int key = 25;

    if (upperCase(cipher_text))
        ascii = 'A';
    else
        ascii = 'a';

    for (char c : cipher_text) {
        if (isalpha(c)) {
            c = (c - ascii + 26 - key) % 26 + ascii;
        }
        plain_text += c;
    }
    return plain_text;
}




