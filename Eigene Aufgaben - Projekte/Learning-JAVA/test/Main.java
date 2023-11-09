package test;
import java.util.Scanner;


public class Main {
    public static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Car car_1 = new Car(Vehicle.get_label(scanner),Vehicle.get_kilometer(scanner));
        Car car_2 = new Car(Vehicle.get_label(scanner),Vehicle.get_kilometer(scanner));
        
        
        scanner.close();
    }
}
