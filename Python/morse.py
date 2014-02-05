# Morse Code Translator
# Python
# Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
# 
# Notes:
# Tested under Python 2.7.3

class Morse:
    morse_code_table = {'A': ".-", 'B': "-...", 'C': "-.-.",
                        'D': "-..", 'E': ".", 'F': "..-.",
                        'G': "--.", 'H': "....", 'I': "..",
                        'J': ".---", 'K': "-.-", 'L': ".-..",
                        'M': "--", 'N': "-.", 'O': "---",
                        'P': ".--.", 'Q': "--.-", 'R': ".-.",
                        'S': "...", 'T': "-", 'U': "..-",
                        'V': "...-", 'W': ".--", 'X': "-..-",
                        'Y': "-.--", 'Z': "--..", '0': "-----",
                        '1': ".----", '2': "..---", '3': "...--",
                        '4': "....-", '5': ".....", '6': "-....",
                        '7': "--...", '8': "---..", '9': "----.",
                        '.': ".-.-.-", ',': "--..--", '?': "..--..",
                        '\'': ".----.", '!': "-.-.--", '/': "-..-.",
                        '(': "-.--.", ')': "-.--.-", '&': ".-...",
                        ':': "---...", ';': "-.-.-.", '=': "-...-",
                        '+': ".-.-.", '-': "-....-", '_': "..--.-",
                        '"': ".-..-.", '$': "...-..-", '@': ".--.-.",
                        ' ': " ", '\n': "\n"}

    def __init__(self):
        pass

    @classmethod
    def get_morse(cls, c):
        return cls.morse_code_table[c.upper()]

    @classmethod
    def to_letter(cls, s):
        for x, y in cls.morse_code_table:
            if y == s:
                return x
