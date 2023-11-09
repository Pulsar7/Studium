package test;

public class Car extends Vehicle {
    public String label;
    public int kilometer;

    public Car(String label, int kilometer) {
        this.label = label;
        this.kilometer = kilometer;
        add_vehicle();
    }
}
