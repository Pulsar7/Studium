#include <stdio.h> // input & output
#include <limits.h> // INT_MAX


int calculate_cents(int amount, int type_of_coin) {
    // 100 Cents = 1 Euro
    // All Cent-Coins are a multiple of five
    int result = ((amount*100)/type_of_coin);
    // int rest = (amount%type_of_coin);
    return result;
}

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

int get_amount(int valid_banknotes[], int amount) {
    printf("Please enter the the amount in Euro:\n");
    amount = get_integer_input();
    if (amount < 0 || (amount*100) > INT_MAX || (amount%5) != 0) {
        amount = -1;
    }
    return amount;
}

int get_coin_type(int valid_coins[], int type_of_coin) {
    int type_status = 1;
    printf("Please specify the type of coin you want:\n");
    type_of_coin = get_integer_input();
    for (int i = 0; i < 4; i++) {
        if (type_of_coin == valid_coins[i]) {
            type_status = 0;
            break;
        }
    }
    if (type_status == 1) {
        type_of_coin = -1;
    }
    return type_of_coin;
}

int main(int argc, int* argv[]) {
    int valid_coins[] = {
        5,10,20,50
    };
    int valid_banknotes[] = {
        5,10,20,50,100
    };
    int amount = valid_banknotes[0],type_of_coin = valid_coins[0];
    amount = get_amount(valid_banknotes,amount);
    if (amount != -1) {
        type_of_coin = get_coin_type(valid_coins,type_of_coin);
        if (type_of_coin != -1) {
            int result = calculate_cents(amount,type_of_coin);
            printf("You get for your %d Euros %d coins %d Cents each\n",amount,result,type_of_coin);
        } else {
            printf("The coin-type is invalid!\n");
        }
    } else {
        printf("Invalid amount!\n");
    }
    return 0;
}