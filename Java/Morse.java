/**
 * Morse Code Translator
 * Java
 * Copyright (C) 2011 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under JDK 1.7.0_25
 */
import java.util.Map;
import java.util.HashMap;

public class Morse {
    private static final Map<Character, String> mm = new HashMap(){{
            put('A', ".-"); put('B', "-..."); put('C', "-.-.");
            put('D', "-.."); put('E', "."); put('F', "..-.");
            put('G', "--."); put('H', "...."); put('I', "..");
            put('J', ".---"); put('K', "-.-"); put('L', ".-..");
            put('M', "--"); put('N', "-."); put('O', "---");
            put('P', ".--."); put('Q', "--.-"); put('R', ".-.");
            put('S', "..."); put('T', "-"); put('U', "..-");
            put('V', "...-"); put('W', ".--"); put('X', "-..-");
            put('Y', "-.--"); put('Z', "--.."); put('0', "-----");
            put('1', ".----"); put('2', "..---"); put('3', "...--");
            put('4', "....-"); put('5', "....."); put('6', "-....");
            put('7', "--..."); put('8', "---.."); put('9', "----.");
            put('.', ".-.-.-"); put(',', "--..--"); put('?', "..--..");
            put('\'', ".----."); put('!', "-.-.--"); put('/', "-..-.");
            put('(', "-.--."); put(')', "-.--.-"); put('&', ".-...");
            put(':', "---..."); put(';', "-.-.-."); put('=', "-...-");
            put('+', ".-.-."); put('-', "-....-"); put('_', "..--.-");
            put('"', ".-..-."); put('$', "...-..-"); put('@', ".--.-.");
            put(' ', " ");
    }};


    public static String lineToMorse(String line) {
        String morseCode = new String();
        char str[]  = line.toUpperCase().toCharArray();
        for (char c : str) {
            morseCode += Morse.getMorse(c);
            if (c != ' ')
                morseCode += " ";
        }

        return morseCode;
    }


    public static String getMorse(char c) {
        return mm.get(c);
    }


    public static String morseToString(String morses) {
        String morse[] = morses.split("  ");
        String r = new String();
        for (String m : morse) {
            for (String s : m.split(" ")) {
                r += Morse.toLetter(s);
            }
            r += " ";
        }

        return r;
    }


    public static char toLetter(String s) {
        for (Map.Entry<Character, String> p : mm.entrySet()) {
            if (p.getValue().equals(s))
                return p.getKey();
        }

        return 0;
    }
}
