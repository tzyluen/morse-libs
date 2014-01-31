<?php
/**
  * Morse Code Translator
  * PHP 
  * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
  *
  * Notes:
  * Tested under PHP 5.4.4-14 CLI
  */

class Morse {
    public static function getMorse($c) {
        switch ($c) {
            case 'A': case 'a': return ".-";
            case 'B': case 'b': return "-...";
            case 'C': case 'c': return "-.-.";
            case 'D': case 'd': return "-..";
            case 'E': case 'e': return ".";
            case 'F': case 'f': return "..-.";
            case 'G': case 'g': return "--.";
            case 'H': case 'h': return "....";
            case 'I': case 'i': return "..";
            case 'J': case 'j': return ".---";
            case 'K': case 'k': return "-.-";
            case 'L': case 'l': return ".-..";
            case 'M': case 'm': return "--";
            case 'N': case 'n': return "-.";
            case 'O': case 'o': return "---";
            case 'P': case 'p': return ".--.";
            case 'Q': case 'q': return "--.-";
            case 'R': case 'r': return ".-.";
            case 'S': case 's': return "...";
            case 'T': case 't': return "-";
            case 'U': case 'u': return "..-";
            case 'V': case 'v': return "...-";
            case 'W': case 'w': return ".--";
            case 'X': case 'x': return "-..-";
            case 'Y': case 'y': return "-.--";
            case 'Z': case 'z': return "--..";
            case '0': return "-----";
            case '1': return ".----";
            case '2': return "..---";
            case '3': return "...--";
            case '4': return "....-";
            case '5': return ".....";
            case '6': return "-....";
            case '7': return "--...";
            case '8': return "---..";
            case '9': return "----.";
            case '.': return ".-.-.-";
            case ',': return "--..--";
            case '?': return "..--..";
            case '\'': return ".----.";
            case '!': return "-.-.--";
            case '/': return "-..-.";
            case '(': return "-.--.";
            case ')': return "-.--.-";
            case '&': return ".-...";
            case ':': return "---...";
            case ';': return "-.-.-.";
            case '=': return "-...-";
            case '+': return ".-.-.";
            case '-': return "-....-";
            case '_': return "..--.-";
            case '"': return ".-..-.";
            case '$': return "...-..-";
            case '@': return ".--.-.";
            case ' ': return " ";
            default: return "";
        }
    }

    public static function toLetter($s) {
        switch ($s) {
            case ".-": return 'A';
            case "-...": return 'B';
            case "-.-.": return 'C';
            case "-..": return 'D';
            case ".": return 'E';
            case "..-.": return 'F';
            case "--.": return 'G';
            case "....": return 'H';
            case "..": return 'I';
            case ".---": return 'J';
            case "-.-": return 'K';
            case ".-..": return 'L';
            case "--": return 'M';
            case "-.": return 'N';
            case "---": return 'O';
            case ".--.": return 'P';
            case "--.-": return 'Q';
            case ".-.": return 'R';
            case "...": return 'S';
            case "-": return 'T';
            case "..-": return 'U';
            case "...-": return 'V';
            case ".--": return 'W';
            case "-..-": return 'X';
            case "-.--": return 'Y';
            case "--..": return 'Z';
            case "-----": return '0';
            case ".----": return '1';
            case "..---": return '2';
            case "...--": return '3';
            case "....-": return '4';
            case ".....": return '5';
            case "-....": return '6';
            case "--...": return '7';
            case "---..": return '8';
            case "----.": return '9';
            case ".-.-.-": return '.';
            case "--..--": return ',';
            case "..--..": return '?';
            case ".----.": return '\'';
            case "-.-.--": return '!';
            case "-..-.": return '/';
            case "-.--.": return '(';
            case "-.--.-": return ')';
            case ".-...": return '&';
            case "---...": return ':';
            case "-.-.-.": return ';';
            case "-...-": return '=';
            case ".-.-.": return '+';
            case "-....-": return '-';
            case "..--.-": return '_';
            case ".-..-.": return '"';
            case "...-..-": return '$';
            case ".--.-.": return '@';
            case " ": return ' ';
            default: return '\0';
        }
    }
}?>
