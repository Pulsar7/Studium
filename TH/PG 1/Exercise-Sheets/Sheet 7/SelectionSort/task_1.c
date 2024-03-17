#include <stdio.h>
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

int sort_array(int *array, int length) { // using the "Selection-Sort-Algorithm"
    int i, j, minIndex, temp;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }

    for (int i = 0; i < length; i++) {
        if (i+1 == length) {
            printf("%d",array[i]);
        } else {
            printf("%d,",array[i]);
        }
    }
    printf("\n");
    return 0;
}


int main(int argc, const char **argv) {
    int my_numbers[MAX_INTEGERS],counter = 0,number;
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
    sort_array(my_numbers,counter); // return obj
    return 0;
}