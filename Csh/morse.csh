#!/bin/csh

set line = "$<"
set chars = `echo $line | fold -w1`
set _code = ""
set morse_code = ""

foreach c ($chars:q)
    switch ($c)
        case 'A':
            set _code = ".-"
            breaksw
        case 'a':
            set _code = ".-"
            breaksw
        case 'B':
            set _code = "-..."
            breaksw
        case 'b':
            set _code = "-..."
            breaksw
        case 'C':
            set _code = "-.-."
            breaksw
        case 'c':
            set _code = "-.-."
            breaksw
        case 'D':
            set _code = "-.."
            breaksw
        case 'd':
            set _code = "-.."
            breaksw
        case 'E':
            set _code = "."
            breaksw
        case 'e':
            set _code = "."
            breaksw
        case 'F':
            set _code = "..-."
            breaksw
        case 'f':
            set _code = "..-."
            breaksw
        case 'G':
            set _code = "--."
            breaksw
        case 'g':
            set _code = "--."
            breaksw
        case 'H':
            set _code = "...."
            breaksw
        case 'h':
            set _code = "...."
            breaksw
        case 'I':
            set _code = ".."
            breaksw
        case 'i':
            set _code = ".."
            breaksw
        case 'J':
            set _code = ".---"
            breaksw
        case 'j':
            set _code = ".---"
            breaksw
        case 'K':
            set _code = "-.-"
            breaksw
        case 'k':
            set _code = "-.-"
            breaksw
        case 'L':
            set _code = ".-.."
            breaksw
        case 'l':
            set _code = ".-.."
            breaksw
        case 'M':
            set _code = "--"
            breaksw
        case 'm':
            set _code = "--"
            breaksw
        case 'N':
            set _code = "-."
            breaksw
        case 'n':
            set _code = "-."
            breaksw
        case 'O':
            set _code = "---"
            breaksw
        case 'o':
            set _code = "---"
            breaksw
        case 'P':
            set _code = ".--."
            breaksw
        case 'p':
            set _code = ".--."
            breaksw
        case 'Q':
            set _code = "--.-"
            breaksw
        case 'q':
            set _code = "--.-"
            breaksw
        case 'R':
            set _code = ".-."
            breaksw
        case 'r':
            set _code = ".-."
            breaksw
        case 'S':
            set _code = "..."
            breaksw
        case 's':
            set _code = "..."
            breaksw
        case 'T':
            set _code = "-"
            breaksw
        case 't':
            set _code = "-"
            breaksw
        case 'U':
            set _code = "..-"
            breaksw
        case 'u':
            set _code = "..-"
            breaksw
        case 'V':
            set _code = "...-"
            breaksw
        case 'v':
            set _code = "...-"
            breaksw
        case 'W':
            set _code = ".--"
            breaksw
        case 'w':
            set _code = ".--"
            breaksw
        case 'X':
            set _code = "-..-"
            breaksw
        case 'x':
            set _code = "-..-"
            breaksw
        case 'Y':
            set _code = "-.--"
            breaksw
        case 'y':
            set _code = "-.--"
            breaksw
        case 'Z':
            set _code = "--.."
            breaksw
        case 'z':
            set _code = "--.."
            breaksw
        case '0':
            set _code = "-----"
            breaksw
        case '1':
            set _code = ".----"
            breaksw
        case '2':
            set _code = "..---"
            breaksw
        case '3':
            set _code = "...--"
            breaksw
        case '4':
            set _code = "....-"
            breaksw
        case '5':
            set _code = "....."
            breaksw
        case '6':
            set _code = "-...."
            breaksw
        case '7':
            set _code = "--..."
            breaksw
        case '8':
            set _code = "---.."
            breaksw
        case '9':
            set _code = "----."
            breaksw
        case '.':
            set _code = ".-.-.-"
            breaksw
        case ',':
            set _code = "--..--"
            breaksw
        case '?':
            set _code = "..--.."
            breaksw
        case '\'':
            set _code = ".----."
            breaksw
        case '!':
            set _code = "-.-.--"
            breaksw
        case '/':
            set _code = "-..-."
            breaksw
        case '(':
            set _code = "-.--."
            breaksw
        case ')':
            set _code = "-.--.-"
            breaksw
        case '&':
            set _code = ".-..."
            breaksw
        case ':':
            set _code = "---..."
            breaksw
        case ';':
            set _code = "-.-.-."
            breaksw
        case '=':
            set _code = "-...-"
            breaksw
        case '+':
            set _code = ".-.-."
            breaksw
        case '-':
            set _code = "-....-"
            breaksw
        case '_':
            set _code = "..--.-"
            breaksw
        case '"':
            set _code = ".-..-."
            breaksw
        case '$':
            set _code = "...-..-"
            breaksw
        case '@':
            set _code = ".--.-."
            breaksw
        case ' ':
            set _code = " "
            echo "space"
            breaksw
        default:
    endsw
    set morse_code = "$morse_code $_code"
end

echo $morse_code
