#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_INTEGERS 5000
#define MAX_ROUNDS 1000


int get_integer(void) {
    int num = 0, ch;
    do {
        ch = getchar();
        if (ch >= 48 && ch <= 57) {
            num = (num * 10 + (ch - 48)); // convert to digit
        } else if ((int)ch != 10) { // checks if ASCII-Code of character is not ' ' (found deviant!)
            num = -1;
            break;
        }
        if (ch == 10) { // ASCII-Code for: '\n'
            break;
        }
    } while (1);
    return num;
}

int sort_array(int *array, int length) { // inefficient: Bubble Sort -> O(n²)
    clock_t start, end;
    double cpu_time_used;
    int counter = 0,current,next,not_changed = 0;
    start = clock();
    while (not_changed <= length) {
        if (counter == 0) {
            not_changed = 0;
        }
        if ((counter+1) <= length-1) {
            if (array[counter] > array[counter+1]) {
                current = array[counter];
                next = array[counter+1];
                array[counter] = next;
                array[counter+1] = current;
            } else {
                not_changed++;
            }
        } else {
            not_changed++;
        }
        counter++;
        if (counter > length) {
            counter = 0;
        }
    }
    /*printf("\n");
    for (int r = 0; r < length; r++) {
        printf("%d ",array[r]);
    }
    printf("\n");*/
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Elements=%d | CPU-time-used=%f\n",length,cpu_time_used);
    return cpu_time_used;
}

long int pseud_rand(void) {
    // printf("%d\n",rand());
    return ((rand()%9223372036854775807)+0); // pseudorandom
}


int main(int argc, const char **argv) {
    srand(time(NULL));
    int counter = 0, array[MAX_INTEGERS] = {0},rounds;
    float calculation_time = 0.0, average_calculation_time = 0.0;
    FILE *file;
    file = fopen("bubble_sort_times.txt", "w");
    fprintf(file, "\r");
    fclose(file);
    for (int r = 0; r <= MAX_INTEGERS; r++) {
        printf("The array with length %d is sorted %d times...",counter,MAX_ROUNDS);
        for (int a = 0; a <= MAX_INTEGERS; a++) {
            array[a] = pseud_rand();
        }
        for (rounds = 0; rounds <= MAX_ROUNDS; rounds++) {
            calculation_time += sort_array(array,counter);
        }
        average_calculation_time = calculation_time/MAX_ROUNDS;
        file = fopen("bubble_sort_times.txt", "a");
        fprintf(file, "%d,%f\n", counter, average_calculation_time);
        fclose(file);
        counter++;
        average_calculation_time = 0.0;
        calculation_time = 0.0;
        printf("O.K.\n");
    }
    return 0;
}
