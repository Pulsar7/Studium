package binomial_coefficient;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter n> ");
        int n = scanner.nextInt();
        System.out.println("Enter k> ");
        int k = scanner.nextInt();
        scanner.close();
        if (n == 0 || k == 0) {
            System.out.println("You entered an invalid value!");
            return;
        }
        calculate(n,k);
    }

    public static void calculate(int n, int k) {
        int result = 0;
        
        System.out.println(result);
    }
}
