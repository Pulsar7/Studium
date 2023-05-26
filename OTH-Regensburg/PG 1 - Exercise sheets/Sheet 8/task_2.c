#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMBER 100000000
#define MIN_NUMBER 0
#define MAX_USER_INPUT_LEN 10


typedef enum {True=0,False=1} BOOLEAN;


int pseudo_random_number(void) {
    return ((rand()%MAX_NUMBER)+MIN_NUMBER);
}

BOOLEAN validate_integer(char number_element) {
    BOOLEAN status = False;
    int ch = (int)number_element;
    if (ch >= 48 && ch <= 57) {
        status = True;
    }
    return status;
}

BOOLEAN check_input(char *user_input) {
    BOOLEAN status = False;
    if (validate_integer(user_input[0]) == True) {
        if (user_input[1] == 'D') {
            if (validate_integer(user_input[2]) == True) {
                if (user_input[3] == '-' || user_input[3] == '+') {
                    if (validate_integer(user_input[4]) == True && validate_integer(user_input[5]) == False) {
                        status = True;
                    }
                }
            }
        }
    }
    return status;
}

int to_number(char number_element) {
    return ((int)number_element - 48);
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int result = 0;
    // k = Dice rolls | length = 1
    // n = Number of sides of the cube | length = 1
    // C = Digit to subtract or to add | length = 1
    char user_input[MAX_USER_INPUT_LEN];
    fgets(user_input,MAX_USER_INPUT_LEN,stdin);
    user_input[strlen(user_input)-1] = '\0'; // to remove the '\n' at the end
    BOOLEAN status = check_input(user_input);
    if (status == True) {
        int k = to_number(user_input[0]);
        int n = to_number(user_input[2]);
        
    } else {
        printf("Your input '%s' has been denied! It's invalid.\n",user_input);
    }
    return 0;
}