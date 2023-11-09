package test;
import java.util.Scanner;

public class Vehicle {
    public static int vehicle_counter = 0;

    protected static void add_vehicle() {
        vehicle_counter++;
    }

    public static String get_label(Scanner scanner) {
        try {
            System.out.print("Enter the vehicle-label> ");
            return scanner.nextLine();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return e.getMessage();
        }
    }

    public static int get_kilometer(Scanner scanner) {
        int kilometer = -1;
        try {
            while (true) {
                try {
                    System.out.print("Enter the vehicle-kilometer> ");
                    kilometer = scanner.nextInt();
                    scanner.nextLine();
                    break;
                } catch (Exception e) {
                    if (e.getMessage() != null) {
                        System.out.println("Incorrect.");
                        scanner.nextLine();
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return kilometer;
    }
}
