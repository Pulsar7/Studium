package src;
import java.util.Scanner;

/*
 * 
 * I used ANSI-Escape-Codes '\033[H\033[2J' in order to "clear" the screen. 
 * 
 * Improved Version:
 * 
 *      - Just update the entities on the map when user presses enter
 *      - No need for 'Thread'
 * 
 */

public class Main {
    public static Hamster hamster;
    public static int refresh_rate = 80; // in milliseconds
    public static Boolean running = true;
    public static int map_window_width = 30;
    public static int map_window_height = 10;
    public static Drawer drawer;
    public static Scanner scanner;
    public static String[] key_options = {
        "Press W/w to walk forward",
        "Press A/a to rotate left",
        "Press D/d to rotate right",
        "Press S/s to show the eaten grains",
        "Press E/e to exit"
    };

    public static void main(String[] args) {
        hamster = new Hamster();
        Map map = new Map(map_window_width,map_window_height);
        drawer = new Drawer(map,hamster);
        scanner = new Scanner(System.in);
        run();
    }

    public static void run() {
        /*
         * Handling the Main-Game-Loop
         * 
         * - Improved Version: Without 'time.sleep'
         * 
         */
        String keyPressed;
        while (running) {
            drawer.draw_map(); // Updates Map-Objects
            show_help();
            keyPressed = get_key_pressed().toUpperCase();
            if (keyPressed.equals("A")) {
                drawer.rotate_left();
            }
            
            if (keyPressed.equals("D")) {
                drawer.rotate_right();
            }
            
            if (keyPressed.equals("W")) {
                drawer.go_forward();
            }
            
            if (keyPressed.equals("S")) {
                drawer.show_ate_grains_counter = 100;
            }
            
            if (keyPressed.equals("E")) {
                System.out.println("Exit.");
                running = false;
            }
            drawer.update_hamster(); // Updates Hamster- position & appearance
        }
        scanner.close();
    }

    private static void show_help() {
        System.out.println("");
        int counter = 1;
        for (String option : key_options) {
            System.out.println("("+counter+") "+option);
            counter++;
        }
        System.out.println(": Don't forget to press enter.");
    }

    private static String get_key_pressed() {
        /*
         * 
         * Capture Keyboard-Input
         * 
         * - Problem: User has to press 'enter' in order confirm the input
         * 
         * 
         * Returns the pressed key
         */
        System.out.print("Enter you option> ");
        String key = scanner.nextLine();
        return key;
    }
}

