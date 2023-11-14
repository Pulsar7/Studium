package src;
import java.lang.Thread;


public class Main {
    public static Hamster hamster;
    public static int refresh_rate = 80; // in milliseconds
    public static Boolean running = true;
    public static Drawer drawer;

    public static void main(String[] args) {
        hamster = new Hamster();
        Map map = new Map(20,10);
        drawer = new Drawer(map,hamster);
        run();
    }

    public static void run() {
        int counter = 0;
        while (running) {
            try {
                drawer.draw_map();
                if (counter > 0) {
                    drawer.go_right();
                }
                drawer.update_hamster();
                Thread.sleep(refresh_rate);
                counter++;
            } catch (InterruptedException e) {
                running = false;
            }
        }
    }
}