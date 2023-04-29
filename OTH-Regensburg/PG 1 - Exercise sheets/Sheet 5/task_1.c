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
    int income,value = 10000, state = 1;
    float taxes = 0.0, tax_rate = 5.0;
    printf("Enter your income:\n");
    income = get_integer_input();
    int counter = 0;
    if (income != -1) {
        if (income > value) {
            while (tax_rate < 50 && state == 1) {
                
            }
        } else {
            taxes = 0;
        }
        printf("You have to pay %.1f €\n",taxes);
    } else {
        printf("Invalid income!\n");
    }
    return 0;
}