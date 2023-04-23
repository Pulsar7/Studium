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
    float amount,total_price;
    int discount; // in percent
    printf("Please enter the quantity:\n");
    amount = get_integer_input();
    if (amount != -1) {
        total_price = 0.80*amount;
        if (amount >= 10 && amount < 50) {
            discount = 3;
        } else if (amount >= 50 && amount < 100) {
            discount = 5;
        } else if (amount >= 100) {
            discount = 8;
        }
        printf("The selling price is %.2f€\n",(total_price-(total_price/100)*discount));
    }
    else {
        printf("The given amount is invalid!\n");
    }
    return 0;
}