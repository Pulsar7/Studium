package src;
import java.lang.Thread;


public class Main {
    public static Hamster hamster;
    public static int refresh_rate = 80; // in milliseconds
    public static Boolean running = true;
    public static Drawer drawer;
    public static String[] key_options = {
        "Press W/w to walk forward",
        "Press A/a to rotate left",
        "Press D/d to rotate right",
        "Press S/s to show the eaten grains",
        "Press E/e to exit"
    };

    public static void main(String[] args) {
        hamster = new Hamster();
        Map map = new Map(11,8);
        drawer = new Drawer(map,hamster);
        run();
    }

    public static void run() {
        /*
         * Handling the Main-Game-Loop
         * 
         * Problem: If user types for example: '1111' and presses enter, the 'rotate_left'-Method is called four times.
         * 
         */
        char keyPressed;
        while (running) {
            try {
                drawer.draw_map(); // Updates Map-Objects
                show_help();
                keyPressed = get_key_pressed();
                if (keyPressed == 'a' || keyPressed == 'A') {
                    drawer.rotate_left();
                }
                
                if (keyPressed == 'd' || keyPressed == 'D') {
                    drawer.rotate_right();
                }
                
                if (keyPressed == 'w' || keyPressed == 'W') {
                    drawer.go_forward();
                }
                
                if (keyPressed == 's' || keyPressed == 'S') {
                    drawer.show_ate_grains_counter = 100;
                }
                
                if (keyPressed == 'e' || keyPressed == 'E') {
                    System.out.println("Exit.");
                    running = false;
                }
                /*
                // Backward option - EXTRA

                if (keyPressed == '6') {
                    drawer.go_backward();
                }
                */
                drawer.update_hamster(); // Updates Hamster- position & appearance
                Thread.sleep(refresh_rate);
            } catch (InterruptedException e) { // thrown by 'Thread.sleep'
                running = false;
            }
        }
    }

    private static void show_help() {
        int counter = 1;
        for (String option : key_options) {
            System.out.println("("+counter+") "+option);
            counter++;
        }
        System.out.println(": Don't forget to press enter.");
    }

    private static char get_key_pressed() {
        /*
         * 
         * Capture Keyboard-Input
         * 
         * - Problem: User has to press 'enter' in order confirm the input
         * 
         * 
         * Returns the pressed key
         */
        char key = '\0';
        System.out.print("Enter you option> ");
        try {
            // Check if a key is available in the input stream
            if (System.in.available() > 0) {
                // Read the key
                key = (char) System.in.read();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return key;
    }
}

