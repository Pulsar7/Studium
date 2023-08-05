package matricesmultiplicator;
// import matricesmultiplicator.Calculator;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        if (args.length >= 2) {
            char[] matrixA = args[0].toCharArray();
            char[] matrixB = args[1].toCharArray();
            Validator validator = new Validator();
            Boolean status = validator.check_matrix(matrixA);
            if (status == true) {
                status = validator.check_matrix(matrixB);
                if (status == true) {
                    Calculator calculator = new Calculator();
                    ArrayList<float[]> converted_matrixA = calculator.convert_char_matrix_to_float(matrixA);
                    ArrayList<float[]> converted_matrixB = calculator.convert_char_matrix_to_float(matrixB);
                    ArrayList<float[]> result_matrix = calculator.multiply_matrices(converted_matrixA, converted_matrixB);
                    printout_matrix(result_matrix,calculator);
                } else {
                    System.out.println("MatrixB is invalid!");
                }
            } else {
                System.out.println("MatrixA is invalid!");
            }
        } else {
            System.out.println("You have to enter the matrixA and matrixB!");
        }
    }

    public static void printout_matrix(ArrayList<float[]> matrix, Calculator calculator) {
        int rows = calculator.get_rows(matrix);
        int columns = calculator.get_columns(matrix);
    }
}
