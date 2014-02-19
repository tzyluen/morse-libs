/**
 * Morse Code Translator
 * Java
 * Copyright (C) 2011 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under JDK 1.7.0_25
 */
import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line  = sc.nextLine();
        
        String morses = Morse.lineToMorse(line);
        System.out.println(morses);

        line = Morse.morseToString(morses);
        System.out.println(line);
    }
}
