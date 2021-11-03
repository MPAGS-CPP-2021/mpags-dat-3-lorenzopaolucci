// Unit test for MPAGSCipher CaesarCipher class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdlib.h>
#include <time.h>
#include <string>
#include "CaesarCipher.hpp"
#include "TransformChar.hpp"

TEST_CASE("Decrypt an encrypted message with a random key", "[decryption]"){

    srand(time(0));
    size_t key{(unsigned) rand() % 26};    

    std::string testStr{"HELLOWORLD"};

    CaesarCipher cipher(key);

    std::string encryptedStr = cipher.applyCipher(testStr, CipherMode::Encrypt);

    REQUIRE( cipher.applyCipher(encryptedStr, CipherMode::Decrypt) == testStr);
}