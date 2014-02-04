/**
 * Morse Code Translator
 * D
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Notes:
 * Tested under GNU gdc (Debian 4.6.3-2) 4.6.3
 */

import std.stdio;
import std.string;
import morse;

void main(string[] args) {
    char[] buf;
    while (stdin.readln(buf)) {
        if (buf.length < 1)
            continue;
        Morse.getLineMorse(buf);
    }
}
