import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char str[]  = sc.nextLine().toCharArray();
        List<String> morseCodeList = new LinkedList();
        String morseCode = new String();

        for (char c : str) {
            morseCode = Morse.getMorse(c);
            morseCodeList.add(morseCode);
            System.out.print(morseCode + " ");
        } System.out.println();

        for (String s : morseCodeList) {
            System.out.print(Morse.toLetter(s));
        } System.out.println();
    }
}
