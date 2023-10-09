package test.person.body;


public class Body {
    private boolean handUp;

    public Body(boolean handUp) {
        this.handUp = handUp;
    }

    public boolean isHandUp() {
        return handUp;
    }

    public void setHandUp(boolean handUp) {
        this.handUp = handUp;
        System.out.println("HAND IS NOW UP");
    }
}
