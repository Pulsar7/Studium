package src;
import src.Body.BodyType;
import src.Map.MapElement;


public class Drawer {
    public Map map;
    public Hamster hamster;

    public Drawer(Map map, Hamster hamster) {
        this.map = map;
        this.hamster = hamster;
        this.hamster.position = this.map.hamster_position;
        this.map.create_map();
    }


    public static void clearScreen() {
        /*
         * 
         * Clears the screen.
         * 
         */
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public void draw_map() {
        /*
         * 
         * Draws the entire Map and all its entities.
         * 
         * 1. Clears the screen
         * 2. Iterates the rows of the Map-Matrix
         * 3. Iterates the columns of the Map-Matrix
         * 
         */
        clearScreen();
        for (int row = 0; row < map.window_height; row++) {
            for (int column = 0; column < map.window_width; column++) {
                if (map.matrix[row][column] == MapElement.WALL) {
                    System.out.print(map.wall.label);
                }
                if (map.matrix[row][column] == MapElement.GRAIN) {
                    System.out.print(map.grain.label);
                }
                if (map.matrix[row][column] == MapElement.AIR) {
                    System.out.print(map.air.label);
                }
                if (map.matrix[row][column] == MapElement.HAMSTER) {
                    System.out.print(this.hamster.body.current_body_element);
                }
            }
            System.out.print("\n");
        }
    }

    public void destroy_element(int row, int column) {
        map.matrix[row][column] = MapElement.AIR;
    }

    public void update_hamster() {
        destroy_element(map.hamster_position.y,map.hamster_position.x);
        map.hamster_position = hamster.position;
        map.matrix[hamster.position.y][hamster.position.x] = MapElement.HAMSTER;
    }


    // Walk

    public boolean check_new_y_position(int new_y_position) {
        /*
         * 
         * Checks if new Y-Coordinate (Row) is valid.
         * 
         * 1. Checks if new Y is less than 0
         * 2. Checks if new Y is bigger than the screen-height (rows)
         * 3. Checks if new Y results to a coordinate where a wall positioned
         * 
         */
        if (new_y_position < 0 || new_y_position >= map.window_height || map.matrix[new_y_position][hamster.position.x] == MapElement.WALL) {
            return false;
        }
        return true;
    }

    public boolean check_new_x_position(int new_x_position) {
        /*
         * 
         * Checks if new X-Coordinate (Column) is valid.
         * 
         * 1. Checks if new X is less than 0
         * 2. Checks if new X is bigger than the screen-width (columns)
         * 3. Checks if new X results to a coordinate where a wall positioned
         * 
         */
        if (new_x_position < 0 || new_x_position >= map.window_width || map.matrix[hamster.position.y][new_x_position] == MapElement.WALL) {
            return false;
        }
        return true;
    }

    public boolean go_forward() {
        int new_y_position = hamster.position.y + hamster.speed;
        if (check_new_y_position(new_y_position)) {
            hamster.position.y = new_y_position;
            hamster.body.current_body_element = hamster.body.get_body_element(BodyType.UP);
            return true;
        }
        return false;
    }

    public boolean go_backward() {
        int new_y_position = hamster.position.y - hamster.speed;
        if (check_new_y_position(new_y_position)) {
            hamster.position.y = new_y_position;
            hamster.body.current_body_element = hamster.body.get_body_element(BodyType.DOWN);
            return true;
        }
        return false;
    }

    public boolean go_left() {
        int new_x_position = hamster.position.x - hamster.speed;
        if (check_new_x_position(new_x_position)) {
            hamster.position.x = new_x_position;
            hamster.body.current_body_element = hamster.body.get_body_element(BodyType.LEFT);
            return true;
        }
        return false;
    }

    public boolean go_right() {
        int new_x_position = hamster.position.x + hamster.speed;
        if (check_new_x_position(new_x_position)) {
            hamster.position.x = new_x_position;
            hamster.body.current_body_element = hamster.body.get_body_element(BodyType.RIGHT);
            return true;
        }
        return false;
    }

}
