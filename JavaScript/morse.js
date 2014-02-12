/**
 * Morse Code Translator
 * JavaScript
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under Iceweasel 17.0.10
 */
var morsemap = {'A': ".-",      'B': "-...",    'C': "-.-.",
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
                ' ': ""};

getMorse = function(line) {
    line = line.toUpperCase();
    var morse="";
    for (var i=0; i<line.length; ++i) {
        morse += morsemap[line.charAt(i)] + " ";
    }
    return morse;
}

toLetter = function(line) {
    var text="";
    var morses = line.split("  ");
    for (var i=0; i<morses.length; ++i) {
        var m = morses[i].split(" ");
        for (var j=0; j<m.length; ++j) {
            var l = function(morse) {
                for (var k in morsemap) {
                    if (morsemap[k] == morse) {
                        return k;
                    }
                }
            }(m[j]);
            text += l;
        }
        text += " ";
    }
    console.log(text);
    return text;
}
