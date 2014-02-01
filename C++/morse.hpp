/**
 * Morse Code Translator
 * C++
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under GNU C++ (Debian 4.7.2-5) 4.7.2, (-std=c++11)
 */
#ifndef _MORSE_HPP
#define _MORSE_HPP

class MorseCode {
private:
    static std::map<char,std::string> morseCodeMap;

public:
    MorseCode();
    ~MorseCode();

    static std::string getMorse(char c);
    static char toLetter(std::string morse);
};
#endif 
