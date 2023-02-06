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
