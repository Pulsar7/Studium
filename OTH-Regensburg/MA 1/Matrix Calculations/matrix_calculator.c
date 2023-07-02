#include <stdio.h>
#define END_MARKER -99999


int get_rows(int **matrix) {
    int rows = 0;
    while (rows < 200) {
        if (matrix[rows][0] == END_MARKER) {
            break;
        }
        rows++;
    }
    rows++;
    return rows;
}

int get_cols(int **matrix) {
    int cols = 0;
    while (cols < 200) {
        if (matrix[0][cols] == END_MARKER) {
            break;
        }
        cols++;
    }
    cols++;
    return cols;
}

int multiply(int **matrixA, int **matrixB, int **result_matrix) {
    
}

int skalar_multiply(int **matrixA, int skalar) {
    
}

int sum(int **matrixA, int **matrixB) {
    // Only matrices whose number of rows is equal to the number of columns can be added.
    int rows = get_cols(matrixA), cols = get_cols(matrixA);
    printf("ROWS=%d | COLS=%d\n",rows,cols);
    int result_matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result_matrix[i][j] = matrixA[i][j]+matrixB[i][j];
        }
    }
    return result_matrix;
}

int show(int **matrix) {
    for (int i = 0; i < get_rows(matrix); i++) {
        for (int j = 0; j < get_cols(matrix); j++) {
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char **argv) {
    int matrixA[4][4] = {
        {1,2,3,END_MARKER},
        {5,6,7,END_MARKER},
        {8,9,10,END_MARKER},
        {END_MARKER,END_MARKER,END_MARKER,END_MARKER}
    };
    int matrixB[4][4] = {
        {6,1,7,END_MARKER},
        {9,0,3,END_MARKER},
        {11,19,8,END_MARKER},
        {END_MARKER,END_MARKER,END_MARKER,END_MARKER}
    };
    int **result_matrix = sum(matrixA,matrixB);
    show(result_matrix);
    return 0;
}