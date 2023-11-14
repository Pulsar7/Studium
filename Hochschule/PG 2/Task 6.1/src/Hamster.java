package src;


public class Hamster {
    public Position position;
    public Body body;
    public int eaten_grains;
    public int speed;

    public Hamster() {
        this.body = new Body();
        this.eaten_grains = 0;
        this.speed = 1;
    }

    public void eat_grain() {
        this.eaten_grains++;
    }
}
