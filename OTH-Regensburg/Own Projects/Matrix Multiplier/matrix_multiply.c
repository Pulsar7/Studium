#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Matrices {
    int number;
    char matrix; // matrix A and B
    int row;
    int column;
    struct Matrices *next;
    struct Matrices *previous;
} Matrices;


Matrices* initialize_root_node(int number, char matrix, int row, int column) {
    Matrices *head_pointer = (Matrices*)calloc(4,sizeof(Matrices));
    head_pointer->next = NULL;
    head_pointer->previous = NULL;
    head_pointer->row = row;
    head_pointer->number = number;
    head_pointer->column = column;
    head_pointer->matrix = matrix;
    return head_pointer;
}

Matrices* add_number(Matrices* head_pointer, int number, char matrix, int row, int column) {
    // append at the end
    Matrices *current = head_pointer;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (Matrices*)calloc(4,sizeof(Matrices));
    current->next->previous = current;
    current->next->next = NULL;
    current->number = number;
    current->column = column;
    current->matrix = matrix;
    current->row = row;
    return current;
}

int get_rows_of_matrix(Matrices* head_pointer, char matrix) {
    Matrices *current = head_pointer;
    int rows = 0;
    while (current != NULL) {
        if (current->matrix == matrix) {
            if (current->row > rows) {
                rows = current->row;
            }
        }
    }
    return rows;
}

int get_columns_of_matrix(Matrices* head_pointer, char matrix) {
    Matrices *current = head_pointer;
    int columns = 0;
    while (current != NULL) {
        if (current->matrix == matrix) {
            if (current->column > columns) {
                columns = current->column;
            }
        }
    }
    return columns;
}

int delete_nodes(Matrices* head_pointer) {
    Matrices* current = head_pointer;
    while (current->next != NULL) {
        current = current->next;
        free(current);
    }
    free(current);
    printf("(+) Deleted nodes");
    return 0;
}


int main(int argc, char* argv[]) {
    srand(time(NULL));
    Matrices* head_pointer;
    int counter = 0;
    do {
        
        counter++;
    } while (counter <= 10);
    delete_notes(head_pointer);
    return 0;
}