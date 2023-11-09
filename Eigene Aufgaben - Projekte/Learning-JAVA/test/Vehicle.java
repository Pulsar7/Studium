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
        try {
            System.out.print("Enter the vehicle-kilometer> ");
            int kilometer = scanner.nextInt();
            scanner.nextLine();
            return kilometer;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }
}
