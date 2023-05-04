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
    int income,value = 10000,state = 1;
    float taxes = 0.0, tax_rate = 5.0, too_much = 0.0;
    printf("Enter your income:\n");
    income = get_integer_input();
    int counter = 0;
    if (income != -1) {
        while (tax_rate < 50) {
            if (income > value) {
                too_much = income-value;
                if (too_much >= 200) {
                    taxes += 2*tax_rate;
                    if (too_much == 200) {
                        break;
                    }
                } else {
                    taxes += (too_much/100)*tax_rate;
                    break;
                }
                value += 200;
                tax_rate += 0.2;
                // printf("Tax-Rate: %f\n",tax_rate);
            } else {
                break;
            }
        }
        printf("You have to pay %.1f for taxes.\n",taxes);
    } else {
        printf("Invalid income!\n");
    }
    return 0;
}