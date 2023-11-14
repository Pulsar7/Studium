package src;
import java.lang.Thread;


public class Main {
    public static Hamster hamster;
    public static int refresh_rate = 70; // in milliseconds
    public static Boolean running = true;
    public static Drawer drawer;

    public static void main(String[] args) {
        hamster = new Hamster();
        Map map = new Map(50,30);
        drawer = new Drawer(map,hamster);
        run();
    }

    public static void run() {
        char keyPressed;
        while (running) {
            try {
                drawer.draw_map();
                keyPressed = get_key_pressed();
                if (keyPressed == 'Q' || keyPressed == 'q') {
                    System.out.println("Exit.");
                    running = false;
                }
                if (keyPressed == 'W' || keyPressed == 'w') {
                    drawer.go_forward();
                }
                if (keyPressed == 'S' || keyPressed == 's') {
                    drawer.go_backward();
                }
                if (keyPressed == 'A' || keyPressed == 'a') {
                    drawer.rotate_left();
                }
                if (keyPressed == 'D' || keyPressed == 'd') {
                    drawer.rotate_right();
                }
                drawer.update_hamster();
                Thread.sleep(refresh_rate);
            } catch (InterruptedException e) {
                running = false;
            }
        }
    }

    private static char get_key_pressed() {
        /*
         * 
         * Capture Keyboard-Input
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

