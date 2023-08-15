package threesudoku;


public class Main {
    public static void main(String[] args) {
        int[][] sudoku = {
            {2,0,3},
            {1,0,0},
            {0,0,1}
        };
        int[][] bitmap = get_bitmap(sudoku);
        
    }

    public static int[][] get_bitmap(int[][] sudoku) {
        int[][] bitmap = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        for (int rows = 0; rows < sudoku.length; rows++) {
            for (int colls = 0; colls < sudoku.length; colls++) {
                if (sudoku[rows][colls] == 0) {
                    bitmap[rows][colls] = 0;
                } else {
                    bitmap[rows][colls] = 1;
                }
            }
        }
        return bitmap;
    }
}
