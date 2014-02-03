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

class Morse {
    static const string[char] morse_code_table;

    /**
     * Unable to initialize a static const associative array:
     * http://www.digitalmars.com/d/archives/digitalmars/D/learn/Associative_array_literal_is_non-constant_32207.html
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
                            '\"': ".-..-.", '$': "...-..-", '@': ".--.-.",
                            ' ': " ",       '\n': "\n"];
    }

    public static string getLineMorse(const string s) {
        return "string";
    }

    public static string getMorse(const char c) {
        return morse_code_table[c];
    }

    public static char toLetter(const string s) {
        return 'c';
    }
}
