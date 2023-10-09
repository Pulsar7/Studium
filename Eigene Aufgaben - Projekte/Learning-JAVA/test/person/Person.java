package test.person;
import test.person.body.*;

public class Person {
    private String name;
    private int age;
    private Body body;
    private Boolean handup;

    public Person(String name, int age, Boolean handup) {
        this.name = name;
        this.age = age;
        this.body = new Body(handup);
    }

    public void put_hand_up() {
        if (this.body.isHandUp() == false) {
            this.body.setHandUp(true);
        } else {
            System.out.println("The hand is already up!");
        }
    }


}
