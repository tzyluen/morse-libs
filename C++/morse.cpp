/**
 * Morse Code Translator
 * C++
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under GNU C++ (Debian 4.7.2-5) 4.7.2, (-std=c++11)
 */
#include <iostream>
#include <map>
#include <algorithm>
#include "morse.hpp"

std::map<char,std::string> MorseCode::morseCodeMap = {
                             {'A', ".-"},     {'B', "-..."},    {'C', "-.-."},
                             {'D', "-.."},    {'E', "."},       {'F', "..-."},
                             {'G', "--."},    {'H', "...."},    {'I', ".."},
                             {'J', ".---"},   {'K', "-.-"},     {'L', ".-.."},
                             {'M', "--"},     {'N', "-."},      {'O', "---"},
                             {'P', ".--."},   {'Q', "--.-"},    {'R', ".-."},
                             {'S', "..."},    {'T', "-"},       {'U', "..-"},
                             {'V', "...-"},   {'W', ".--"},     {'X', "-..-"},
                             {'Y', "-.--"},   {'Z', "--.."},
                             {'0', "-----"},  {'1', ".----"},   {'2', "..---"},
                             {'3', "...--"},  {'4', "....-"},   {'5', "....."},
                             {'6', "-...."},  {'7', "--..."},   {'8', "---.."},
                             {'9', "----."},
                             {'.', ".-.-.-"}, {',', "--..--"},  {'?', "..--.."},
                             {'\'', ".----."},{'!', "-.-.--"},  {'/', "-..-."},
                             {'(', "-.--."},  {')', "-.--.-"},  {'&', ".-..."},
                             {':', "---..."}, {';', "-.-.-."},  {'=', "-...-"},
                             {'+', ".-.-."},  {'-', "-....-"},  {'_', "..--.-"},
                             {'\"', ".-..-."},{'$', "...-..-"}, {'@', ".--.-."},
                             {' ', " "},      {'\n', "\n"}
};

MorseCode::MorseCode() {
}

MorseCode::~MorseCode() {
}

std::string MorseCode::getMorse(char c) {
    return MorseCode::morseCodeMap[c];
}

char MorseCode::toLetter(std::string morse) {
    std::map<char,std::string> m = MorseCode::morseCodeMap;

    for (std::map<char,std::string>::iterator it = m.begin(); it != m.end(); ++it) {
        if (it->second == morse) {
            return it->first;
        }
    }
    return NULL;
}
