#include <gtest/gtest.h>
#include <string>
#include "../include/Decoder.h"

TEST(DecoderTest, EmptyString) {
  EXPECT_EQ("", Decoder::decryptCaesarShift(""));
}

TEST(DecoderTest, Numbers) {
  EXPECT_EQ("1234567890", Decoder::decryptCaesarShift("1234567890"));
}

TEST(DecoderTest, SpecialCharacters) {
  EXPECT_EQ(" !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~", Decoder::decryptCaesarShift(" !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"));
}

TEST(DecoderTest, ShiftOneNoSpacesLowercase) {
  EXPECT_EQ("uifrvjdlcspxogpykvnqtpwfsuifmbazeph",
            Decoder::decryptCaesarShift("thequickbrownfoxjumpsoverthelazydog"));
}

TEST(DecoderTest, ShiftOneNoSpacesUppercase) {
  EXPECT_EQ("UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH",
            Decoder::decryptCaesarShift("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG"));
}
TEST(DecoderTest, ShiftOneSpacesLowercase) {
  EXPECT_EQ("uif rvjdl cspxo gpy kvnqt pwfs uif mbaz eph",
            Decoder::decryptCaesarShift("the quick brown fox jumps over the lazy dog"));
}

TEST(DecoderTest, ShiftOneSpacesUppercase) {
  EXPECT_EQ("UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH",
            Decoder::decryptCaesarShift("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG"));
}

TEST(DecoderTest, ShiftFiveSentenceUppercase) {
  std::string cipherText = "NS HWDUYTLWFUMD, F HFJXFW HNUMJW, FQXT PSTBS FX "
                           "HFJXFW'X HNUMJW, YMJ XMNKY HNUMJW, HFJXFW'X HTIJ "
                           "TW HFJXFW XMNKY, NX TSJ TK YMJ XNRUQJXY FSI RTXY "
                           "BNIJQD PSTBS JSHWDUYNTS YJHMSNVZJX. NY NX F YDUJ "
                           "TK XZGXYNYZYNTS HNUMJW NS BMNHM JFHM QJYYJW NS "
                           "YMJ UQFNSYJCY NX WJUQFHJI GD F QJYYJW XTRJ KNCJI "
                           "SZRGJW TK UTXNYNTSX ITBS YMJ FQUMFGJY. KTW "
                           "JCFRUQJ, BNYM F QJKY XMNKY TK 3, I BTZQI GJ "
                           "WJUQFHJI GD F, J BTZQI GJHTRJ G, FSI XT TS. YMJ "
                           "RJYMTI NX SFRJI FKYJW OZQNZX HFJXFW, BMT ZXJI NY "
                           "NS MNX UWNAFYJ HTWWJXUTSIJSHJ.";

  std::string plainText = "IN CRYPTOGRAPHY, A CAESAR CIPHER, ALSO KNOWN AS "
                          "CAESAR'S CIPHER, THE SHIFT CIPHER, CAESAR'S CODE "
                          "OR CAESAR SHIFT, IS ONE OF THE SIMPLEST AND MOST "
                          "WIDELY KNOWN ENCRYPTION TECHNIQUES. IT IS A TYPE "
                          "OF SUBSTITUTION CIPHER IN WHICH EACH LETTER IN THE"
                          " PLAINTEXT IS REPLACED BY A LETTER SOME FIXED "
                          "NUMBER OF POSITIONS DOWN THE ALPHABET. FOR "
                          "EXAMPLE, WITH A LEFT SHIFT OF 3, D WOULD BE "
                          "REPLACED BY A, E WOULD BECOME B, AND SO ON. THE "
                          "METHOD IS NAMED AFTER JULIUS CAESAR, WHO USED IT "
                          "IN HIS PRIVATE CORRESPONDENCE.";

  EXPECT_EQ(plainText, Decoder::decryptCaesarShift(cipherText));
}

TEST(DecoderTest, ShiftThreeSentenceMixcase) {
  std::string cipherText = "Lq fubswrjudskb, d Fdhvdu flskhu, dovr nqrzq dv "
                           "Fdhvdu'v flskhu, wkh vkliw flskhu, Fdhvdu'v frgh "
                           "ru Fdhvdu vkliw, lv rqh ri wkh vlpsohvw dqg prvw "
                           "zlghob nqrzq hqfubswlrq whfkqltxhv. Lw lv d wbsh "
                           "ri vxevwlwxwlrq flskhu lq zklfk hdfk ohwwhu lq "
                           "wkh sodlqwhaw lv uhsodfhg eb d ohwwhu vrph ilahg "
                           "qxpehu ri srvlwlrqv grzq wkh doskdehw. Iru "
                           "hadpsoh, zlwk d ohiw vkliw ri 3, G zrxog eh "
                           "uhsodfhg eb D, H zrxog ehfrph E, dqg vr rq. Wkh "
                           "phwkrg lv qdphg diwhu Mxolxv Fdhvdu, zkr xvhg lw "
                           "lq klv sulydwh fruuhvsrqghqfh.";

  std::string plainText = "In cryptography, a Caesar cipher, also known as "
                          "Caesar's cipher, the shift cipher, Caesar's code "
                          "or Caesar shift, is one of the simplest and most "
                          "widely known encryption techniques. It is a type "
                          "of substitution cipher in which each letter in the"
                          " plaintext is replaced by a letter some fixed "
                          "number of positions down the alphabet. For "
                          "example, with a left shift of 3, D would be "
                          "replaced by A, E would become B, and so on. The "
                          "method is named after Julius Caesar, who used it "
                          "in his private correspondence.";

  EXPECT_EQ(plainText, Decoder::decryptCaesarShift(cipherText));
}
