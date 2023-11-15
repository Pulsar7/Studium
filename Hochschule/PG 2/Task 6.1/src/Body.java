package src;

public class Body {
    public enum BodyType {
        LEFT, RIGHT, DOWN, UP
    }
    public String current_body_element;

    public Body() {
        this.current_body_element = get_body_element(BodyType.UP);
    }

    public String get_body_element(BodyType body_type) {
        /*
         * Returns the current Body-Element as a 'String'
         * 
         * 
         */
        if (body_type == BodyType.LEFT) {
            return "<";
        }

        if (body_type == BodyType.RIGHT) {
            return ">";
        }

        if (body_type == BodyType.DOWN) {
            return "v";
        }
        return "^";
    }
}
