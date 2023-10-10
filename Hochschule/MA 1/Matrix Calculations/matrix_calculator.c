#include <stdio.h>
#include <stdlib.h>
#define END_MARKER -99999


int multiply(int **matrixA, int **matrixB, int **result_matrix) {
    
}

int skalar_multiply(int **matrixA, int skalar) {
    
}

int** sum(int **matrixA, int **matrixB, int rows_A, int rows_B) {
    // Only matrices whose number of rows is equal to the number of columns can be added.
    printf("ROWS-A=%d | ROWS-B=%d\n",rows_A,rows_B);
    /*int **result_matrix = (int**)malloc(rows_A * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result_matrix[i][j] = matrixA[i][j]+matrixB[i][j];
        }
    }
    return (int**)result_matrix;*/
}

/*int show(int **matrix) {
    for (int i = 0; i < get_rows(matrix); i++) {
        for (int j = 0; j < get_cols(matrix); j++) {
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}*/



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

    int rows_A = 0, rows_B = 0;
    while (rows_A < 200) {
        if (matrixA[rows_A][0] == END_MARKER) {
            rows_A++;
            break;
        }
        rows_A++;
    }
    while (rows_B < 200) {
        if (matrixB[rows_B][0] == END_MARKER) {
            rows_B++;
            break;
        }
        rows_B++;
    }
    
    int **result_matrix = sum((int**)matrixA,(int**)matrixB,rows_A,rows_B);
    // show(result_matrix);
    // free(result_matrix); // free allocated space
    return 0;
}