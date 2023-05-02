#include <math.h>
#include <stdio.h>


int get_integer_input() {
    int num = 0, ch;
    do {
        ch = getchar();
        if (ch >= 48 && ch <= 57) { // checks if ASCII-Code of character is between 48 and 57 (numbers 0 - 9) --> "Aufgabenblatt 2"
            num = (num * 10 + (ch - 48)); // convert to digit
        } else if ((int)ch != 10) { // checks if ASCII-Code of character is not ' ' ( found deviant! )
            num = -1;
            break;
        }
        if (ch == '\n') {
            break;
        }
    } while (1);
    return num;
}

int main(int argc, char* argv[]) {
    int number,i = 0,counter = 0;
    double value = 0.0;
    printf("Enter a number:\n");
    number = get_integer_input();
    if (number != -1) {
        for (number = 2; number < 200; number++) {
            int primfactor_state = 1;
            for (i = 1; i <= sqrt(number); i++) {
                if ((number%i) == 0 && i != 1) {
                    primfactor_state = 0;
                    break;
                }
            }
            if (primfactor_state == 1) {
                printf("The number %d is a primfactor!\n",number);
            } else {
                printf("The number %d isn't a primfactor\n",number);
            }
        }
    } else {
        printf("The number is invalid!\n");
    }
    return 0;
}