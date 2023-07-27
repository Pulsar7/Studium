package Palindrome;
import java.util.HashMap;
import java.util.Scanner; // for user-input


public class Main {

    static char[] make_word_uppercase(String word) {
        // simpler alternative: word.toUpperCase(); :D
        // just for fun:
        char[] letters = word.toCharArray();
        HashMap<Character,Character> lower_to_upper_hashmap = new HashMap<Character,Character>();
        char[] lower_alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();
        char[] upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
        for (int i = 0; i < lower_alphabet.length; i++) {
            lower_to_upper_hashmap.put(lower_alphabet[i],upper_alphabet[i]);
        }
        char[] new_word = letters;
        for (int i = 0; i < word.length(); i++) {
            if ((int)letters[i] >= 97 && (int)letters[i] <= 122) { // ASCII Codes of 'a' and 'z'
                new_word[i] = lower_to_upper_hashmap.get(letters[i]);
            } else {
                new_word[i] = letters[i];
            }
        }
        return new_word;
    }
    
    static int check_word(String this_word) {
        char[] word = make_word_uppercase(this_word);
        int status = 1; // for true
        for (int i = 0; i < word.length; i++) {
            try {
                if (word[i] != word[word.length-1-i]) {
                    status = 0; // for false
                    break;
                }
            } catch (Exception e) {
                System.out.println("An error occured: "+e.toString());
                status = -1; // for unknown
                break;
            }
        }
        return status;
    }

    public static void main(String[] args) {
        String word = "";
        if (args.length >= 1) {
            word = args[0];
        } else {
            Scanner scanner_obj = new Scanner(System.in);
            System.out.print("Enter the word: ");
            word = scanner_obj.nextLine();
            scanner_obj.close();
        }
        int status = check_word(word);
        if (status == 1) {
            System.out.println("The word '"+word+"' is a palindrome.");
        } else if (status == 0) {
            System.out.println("The word '"+word+"' is not a palindrome!");
        } else {
            System.out.println("Couldn't determine if it's a palindrome or not!");
        }
    }
}