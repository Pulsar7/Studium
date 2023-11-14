package src;

public class Obstacle {
    public enum ObjectType {
        FOOD, BARRIER;
    }
    public String label;
    public ObjectType object_type;

    public Obstacle(String label, ObjectType object_type) {
        this.label = label;
        this.object_type = object_type;
    }
}
