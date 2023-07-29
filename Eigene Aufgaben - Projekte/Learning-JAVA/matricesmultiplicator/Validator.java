package matricesmultiplicator;



public class Validator {
    public Boolean check_matrix(char[] matrix) {
        Boolean status = false;
        try {
            int elements = matrix.length;
            int opened_brackets_counter = 0;
            int closed_brackets_counter = 0;
            if (matrix[elements-1] == ']') {
                for (int i = 0; i < elements; i++) {
                    // System.out.println((int)matrix[i]+" "+matrix[i]);
                    if (i+1 <= elements-1) {
                        if (((int)matrix[i] >= 48 && (int)matrix[i] <= 57) && matrix[i+1] != ']' && matrix[i+1] != ',' && ((int)matrix[i+1] < 48 || (int)matrix[i+1] > 57)) {
                            // current element is a digit between 0 and 9
                            // -> the next element has to be a ',' or ']' or another digit between 0 and 9
                            return status;
                        }
                        if (matrix[i] == '-' && ((int)matrix[i+1] < 48 || (int)matrix[i+1] > 57)) {
                            // current element is a '-'
                            // -> the next element has to be a digit between 0 and 9
                            return status;
                        }
                        if (matrix[i] == '+' && ((int)matrix[i+1] < 48 || (int)matrix[i+1] > 57)) {
                            // current element is a '+'
                            // -> the next element has to be a digit between 0 and 9
                            return status;
                        }
                        if (matrix[i] == '[' && ((int)matrix[i+1] < 48 || (int)matrix[i+1] > 57) && matrix[i+1] != '-' && matrix[i+1] != '+' && matrix[i+1] != '[') {
                            // current element is a '['
                            // -> the next element has to be a digit between 0 and 9 or a '-' or a '+' or another '['
                            return status;
                        } else if (matrix[i] == '[') {
                            opened_brackets_counter++;
                        }
                        if (matrix[i] == ']' && matrix[i+1] != ',' && matrix[i+1] != ']') {
                            // current element is a ']'
                            // -> the next element has to be a ',' or another ']'
                            return status;
                        } else if (matrix[i] == ']') {
                            closed_brackets_counter++;
                        }
                        if (matrix[i] == ',' && matrix[i+1] != '[' && ((int)matrix[i+1] < 48 || (int)matrix[i+1] > 57) && matrix[i+1] != '+' && matrix[i+1] != '-') {
                            // current element is a ','
                            // -> the next element has to be a '[' or a digit between 0 and 9 or a '-' or a '+'
                            return status;
                        }
                    } else {
                        if (matrix[i] == ']') {
                            closed_brackets_counter++;
                        }
                    }
                }
                if (opened_brackets_counter == closed_brackets_counter) {
                    status = true;
                } else {
                    System.out.println("There're more opened brackets than closed!");
                }
            } else {
                System.out.println("The last element of a matrix has to be a ']'!");
            }
        } catch (Exception e) {
            System.out.println("An error occured while trying to check matrix -> "+e.toString());
        }
        return status;
    }
}
