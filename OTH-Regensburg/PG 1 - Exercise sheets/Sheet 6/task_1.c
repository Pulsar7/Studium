#include <stdio.h>


int calculate_coins(int amount, int coins) {
    return amount*100/coins;
}

int main(int argc, char *argv[]) {
    printf("%d\n",calculate_coins(10,0)); // error example
    return 0;
}