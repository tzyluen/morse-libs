/**
 * Morse Code Translator
 * D
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under GNU gdc (Debian 4.6.3-2) 4.6.3
 */
module morse;
import std.stdio;
import std.string;
import core.exception;

class Morse {
    static const string[char] morse_code_table;

    /**
     * Unable to initialize a static const associative array:
     * http://www.digitalmars.com/d/archives/digitalmars/D/learn/Associative_array_literal_is_non-constant_32207.html
     * and therefore, use this() :
     */
    static this() {
        morse_code_table = ['A': ".-",      'B': "-...",    'C': "-.-.",
                            'D': "-..",     'E': ".",       'F': "..-.",
                            'G': "--.",     'H': "....",    'I': "..",
                            'J': ".---",    'K': "-.-",     'L': ".-..",
                            'M': "--",      'N': "-.",      'O': "---",
                            'P': ".--.",    'Q': "--.-",    'R': ".-.",
                            'S': "...",     'T': "-",       'U': "..-",
                            'V': "...-",    'W': ".--",     'X': "-..-",
                            'Y': "-.--",    'Z': "--..",    '0': "-----",
                            '1': ".----",   '2': "..---",   '3': "...--",
                            '4': "....-",   '5': ".....",   '6': "-....",
                            '7': "--...",   '8': "---..",   '9': "----.",
                            '.': ".-.-.-",  ',': "--..--",  '?': "..--..",
                            '\'': ".----.", '!': "-.-.--",  '/': "-..-.",
                            '(': "-.--.",   ')': "-.--.-",  '&': ".-...",
                            ':': "---...",  ';': "-.-.-.",  '=': "-...-",
                            '+': ".-.-.",   '-': "-....-",  '_': "..--.-",
                            '\"': ".-..-.", '$': "...-..-", '@': ".--.-."];
    }

    public static string lineToMorse(const char[] s) {
        auto buf = toUpper(s);
        string m = "";
        for (size_t i = 0; i < buf.length - 1; ++i) {
            try {
                m ~= format("%s ", Morse.getMorse(buf[i]));
            } catch (RangeError e) {
                m ~= format("%s ", buf[i]);
            }
        }
        return m;
    }

    public static string getMorse(const char c) {
        return morse_code_table[c];
    }

    public static char toLetter(const string s) {
        if (s == " ") return ' ';
        foreach (key, value; morse_code_table) {
            if (value == s)
                return key;
        }
        return ' ';
    }

    public static string morseToLine(const string s) {
        auto listOfMorse = s.split("  ");
        string line = "";
        foreach (morses; listOfMorse) {
            auto morse = morses.split(" ");
            /*for (size_t i = 0; i < morse.length; ++i) {
                line ~= format("%s", Morse.toLetter(morse[i]));
            }*/
            foreach (m; morse) {
                line ~= format("%s", Morse.toLetter(m));
            }
        }
        return line;
    }
}
