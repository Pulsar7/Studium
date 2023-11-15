package src;
import java.lang.Thread;


public class Main {
    public static Hamster hamster;
    public static int refresh_rate = 50; // in milliseconds
    public static Boolean running = true;
    public static Drawer drawer;

    public static void main(String[] args) {
        hamster = new Hamster();
        Map map = new Map(50,20);
        drawer = new Drawer(map,hamster);
        run();
    }

    public static void run() {
        /*
         * Handling the Main-Game-Loop
         * 
         * 
         */
        char keyPressed;
        while (running) {
            try {
                drawer.draw_map(); // Updates Map-Objects
                keyPressed = get_key_pressed();
                if (keyPressed == '1') {
                    drawer.rotate_left();
                }
                
                if (keyPressed == '2') {
                    drawer.rotate_right();
                }
                
                if (keyPressed == '3') {
                    drawer.go_forward();
                }
                
                if (keyPressed == '4') {
                    System.out.println("You ate "+hamster.eaten_grains+" grains");
                }
                
                if (keyPressed == '5') {
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
        String[] options = {
            "Rotate Left",
            "Rotate Right",
            "Go Forward",
            "Show eaten grains",
            "Exit",
            // "Go Backward", // EXTRA
        };
        int counter = 0;
        for (String option : options) {
            counter++;
            System.out.println("( " + counter + " ) "+option);
        }
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

