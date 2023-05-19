#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_INTEGERS 100


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
    printf("Sorting array with length %d...",length);
    int counter = 0,current,next,not_changed = 0;
    clock_t start, end;
    double cpu_time_used;
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
                // array[counter],array[counter+1] = array[counter+1],array[counter]; // NOT?! the same 
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
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("O.K.\n");
    /*for (int i = 0; i < length; i++) {
        if (i+1 == length) {
            printf("%d",array[i]);
        } else {
            printf("%d,",array[i]);
        }
    }
    printf("\n");*/
    // printf("Elements=%d | CPU-time-used=%f\n",length,cpu_time_used);
    FILE *file;
    file = fopen("bubble_sort_times.txt", "a"); // Open the file in write mode
    fprintf(file, "%d,%f\n", length, cpu_time_used);
    fclose(file);
    return 0;
}

int pseud_rand(void) {
    return ((rand()%2500)+0); // pseudorandom
}


int main(int argc, const char **argv) {
    srand(time(NULL));
    int counter = 0, array[2500] = {0};
    for (int a = 0; a <= 2500; a++) {
        array[a] = pseud_rand();
    }
    for (int r = 0; r <= 2499; r++) {
        sort_array(array,counter);
        counter++;
    }
    /*int my_numbers[MAX_INTEGERS],counter = 0,number;
    while (counter <= MAX_INTEGERS) {
        number = get_integer();
        if (number != -1) {
            my_numbers[counter] = number;
        } else {
            // printf("Input error!\n");
            break;
        }
        counter++;
    }
    int maximum = 0,minimum = 0;
    float sum = 0.0,average = 0.0;
    for (int i; i < counter; i++) {
        if (i == 0) {
            minimum = my_numbers[i];
        }
        sum += my_numbers[i];
        if (my_numbers[i] > maximum) {
            maximum = my_numbers[i];
        } else if (my_numbers[i] < minimum) {
            minimum = my_numbers[i];
        }
    }
    average = (sum/(float)counter);
    printf("Minium: %d\n",minimum);
    printf("Maximum: %d\n",maximum);
    printf("Average: %f\n",average);
    printf("Unsorted Integer-Array: ");
    for (int i = 0; i < counter; i++) {
        if (i+1 == counter) {
            printf("%d",my_numbers[i]);
        } else {
            printf("%d,",my_numbers[i]);
        }
    }
    printf("\nSorted Integer-Array: ");
    sort_array(my_numbers,counter); // return obj*/
    return 0;
}