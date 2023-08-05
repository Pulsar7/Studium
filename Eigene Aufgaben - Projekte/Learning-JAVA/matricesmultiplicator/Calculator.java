package matricesmultiplicator;
import java.util.ArrayList;


public class Calculator {
    public ArrayList<float[]> convert_char_matrix_to_float(char[] matrix) {
        int array_len = matrix.length;
        int rows = char_matrix_get_rows(matrix, array_len);
        
        ArrayList<float[]> converted_matrix = new ArrayList<>();
        for (int i = 0; i < array_len; i++) {
            if (matrix[i] == '[') {

            }
        }
        return converted_matrix;
    }

    public ArrayList<float[]> multiply_matrices(ArrayList<float[]> matrixA, ArrayList<float[]> matrixB) {
        ArrayList<float[]> result_matrix = new ArrayList<>();
        return result_matrix;
    }

    public int char_matrix_get_rows(char[] matrix, int length) {
        int rows = 0;

        return rows;
    }

    public int get_rows(ArrayList<float[]> matrix) {
        int rows = 0;
        
        return rows;
    }

    public int get_columns(ArrayList<float[]> matrix) {
        int columns = 0;
        return columns;
    }
}