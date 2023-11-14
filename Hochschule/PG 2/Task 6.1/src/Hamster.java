package src;
import src.Body.BodyType;


public class Hamster {
    public Position position;
    public Body body;
    public int eaten_grains;
    public int speed;

    public Hamster() {
        // this.position = new Position(0, 0);
        this.body = new Body();
        this.eaten_grains = 0;
        this.speed = 1;
    }

    public void eat_grain() {
        this.eaten_grains++;
    }
}
