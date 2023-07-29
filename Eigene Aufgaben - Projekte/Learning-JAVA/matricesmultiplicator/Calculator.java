package matricesmultiplicator;
import java.util.ArrayList;


public class Calculator {
    public ArrayList<float[]> convert_char_matrix_to_float(char[] matrix) {
        int array_len = matrix.length;
        int rows = char_matrix_get_rows(matrix, array_len);
        
        float[] converted_matrix = {};
        for (int i = 0; i < array_len; i++) {
            if (matrix[i] == '[') {

            }
        }
        return converted_matrix;
    }

    public float[] multiply_matrices(float[] matrixA, float[] matrixB) {
        float[] result_matrix = {};
        return result_matrix;
    }

    public int char_matrix_get_rows(char[] matrix, int length) {
        int rows = 0;

        return rows;
    }

    public int get_rows(float[] matrix) {
        int rows = 0;
        
        return rows;
    }

    public int get_columns(float[] matrix) {
        int columns = 0;
        return columns;
    }
}