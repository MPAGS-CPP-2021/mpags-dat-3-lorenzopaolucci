#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <iostream>
#include <vector>
#include "CaesarMode.hpp"

class CaesarCipher{
  public:       
    CaesarCipher(std::size_t key);
    
    CaesarCipher(std::string key);

    std::string applyCipher(std::string& inputText, CipherMode mode) const;

  private:
    std::size_t       key_=0;
    std::vector<char> alphabet_;
    std::size_t       alphabetSize_;
};

#endif 