package euclideanalgorithm;


public class Main {
    public static void main(String[] args) {
        if (args.length == 2) {
            char[] first_number = args[0].toCharArray();
            char[] second_number = args[1].toCharArray();
            if (check_number(first_number) == true) {
                if (check_number(second_number) == true) {
                    int numberA = convert_char_number_to_integer(first_number);
                    int numberB = convert_char_number_to_integer(second_number);
                    int result = 0;
                    if (numberA-numberB > 1000 || numberB-numberA > 1000) {
                        result = iterative_euklidic_algorithm(numberA,numberB);
                    } else {
                        result = recursive_euklidic_algorithm(numberA,numberB);
                    }
                    System.out.println("ggT("+numberA+","+numberB+") = "+result);
                } else {
                    System.out.println("The second number is invalid.");
                }
            } else {
               System.out.println("The first number is invalid.");
            }
        } else {
            System.out.println("Too few arguments!");
        }
    }

    public static boolean check_number(char[] number) {
        boolean valid_number = true;
        int counter = 0;
        for (char c : number) {
            if (((int)c < 48 || (int)c > 57) && c != '+' && c != '-') {
                valid_number = false;
                break;
            }
            if (counter > 0 && (c == '+' || c == '-')) {
                valid_number = false;
                break;
            }
            if (c == '-') {
                number[counter] = '+';
            }
            counter++;
        }
        return valid_number;
    }

    public static int convert_char_number_to_integer(char[] number) {
        return Integer.parseInt(new String(number));
    }

    public static int iterative_euklidic_algorithm(int a, int b) {
        while (a != b && a != 1 && b != 1) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        if (a == 1) {
            return a;
        }
        return b;
    }

    public static int recursive_euklidic_algorithm(int a, int b) {
        if (a == 1 || b == 1 || a == b) {
            if (a == 1) {
                return a;
            }
            return b;
        } else {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
            return recursive_euklidic_algorithm(a, b);
        }
    }
}
