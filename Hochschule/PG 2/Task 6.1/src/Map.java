package src;
import src.obstacles.Grain;
import src.obstacles.Wall;
import src.obstacles.Air;


public class Map {
    public enum MapElement {
        AIR, WALL, GRAIN, HAMSTER;
    }
    public MapElement[][] matrix;
    public int window_width;
    public int window_height;
    public Wall wall = new Wall();
    public Grain grain = new Grain();
    public Air air = new Air();
    public Position hamster_position;

    public Map(int window_width, int window_height) {
        this.window_width = window_width;
        this.window_height = window_height;
        this.hamster_position = new Position(3,3);
        this.matrix = new MapElement[window_height][window_width];
    }

    public void create_map() {
        for (int row = 0; row < window_height; row++) {
            for (int column = 0; column < window_width; column++) {
                if (row == 0 || column == 0 || row == window_height-1 || column == window_width-1) {
                    matrix[row][column] = MapElement.WALL;
                } else {
                    matrix[row][column] = MapElement.AIR;
                }
            }
        }
        matrix[hamster_position.y][hamster_position.x] = MapElement.HAMSTER;
    }
}
