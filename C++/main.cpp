/**
 * Morse Code Translator
 * C++
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under GNU C++ (Debian 4.7.2-5) 4.7.2, (-std=c++11)
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "morse.hpp"

int main(int argc, char **argv)
{
    std::vector<char> morseCodeListKeys;
    std::vector<std::string> morseCodeListValues;

    for (std::string line; getline(std::cin, line);) {
        for (int i = 0; i < line.length(); ++i) {
            std::string morse = MorseCode::getMorse(toupper(line[i]));
            std::cout<<morse<<" ";
            morseCodeListKeys.push_back(line[i]);
            morseCodeListValues.push_back(morse);
        } std::cout<<std::endl;
    }

    std::vector<std::string>::iterator it;
    for (it = morseCodeListValues.begin(); it < morseCodeListValues.end(); ++it) {
        std::cout<<MorseCode::toLetter(*it);
    } std::cout<<std::endl;

    return 0;
}
