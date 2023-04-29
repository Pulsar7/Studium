#include <stdio.h>


int get_integer_input() {
    int num = 0, ch;
    do {
        ch = getchar();
        if (ch >= 48 && ch <= 57) {
            num = (num * 10 + (ch - 48)); // convert to digit
        } else if ((int)ch != 10) { // checks if ASCII-Code of character is not ' ' (found deviant!)
            num = -1;
            break;
        }
        if (ch == '\n') {
            break;
        }
    } while (1);
    return num;
}

int invalid_input(int *zahl) {
    printf("Die Zahl '%d' wird nicht akzeptiert!\n",*zahl);
}

int main(int argc, char* argv[]) {
    int *numbers[100] = {0};
    char *operators[] = {
        '+','-','/','*','%'
    };
    int quit = 0, number;
    float result;
    char operator;
    while (quit == 0) {
        printf("Geben Sie eine Zahl ein:\n");
        number = get_integer_input();
        if (number != -1) {
            printf("Geben Sie einen Operator ein:\n");
            scanf("%c",&operator);
            if (operator == 'q') {
                quit = 1;
            } else {
                
            }
        } else {
            invalid_input(&number);
            quit = 1;
        }
    }
    printf("Result = %f\n");
    return 0;
}