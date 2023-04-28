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

int main(int argc, char* argv[]) {
    int income,value;
    float taxes = 0.0;
    income = get_integer_input();
    if (income != -1) {
        if (income > 10000) {
            value = 10000;
            while (1) {
                value += 200;
                if (income > value) {

                } else {
                    break;
                }
            }
        } else {
            taxes = 0;
        }
        printf("You have to pay %f €\n",taxes);
    } else {
        printf("Invalid income!\n");
    }
    return 0;
}