#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROUNDS 3


int roll(int min, int max) {
    return ((rand()%max)+min); // pseudorandom
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    int number, dices, max_dices = 5, user_input, result = 0;
    int min = 1, max = 6;
    int rolls[5] = {0};
    for (int rounds = 0; rounds < MAX_ROUNDS; rounds++) {
        for (dices = 0; dices < max_dices; dices++) {
            rolls[dices] = roll(min,max);
            printf("(%d) -> number: %d\n",dices,rolls[dices]);
        }
        while (max_dices > 1) {
            printf("Enter the dices to delete (enter -1 to end):\n");
            scanf("%d",&user_input);
            if ((user_input < 5 && user_input >= 0) || user_input == -1) {
                if (user_input != -1) {
                    rolls[user_input] = 0;
                    max_dices--;
                } else {
                    break;
                }
            } else {
                printf("The number %d is invalid!",user_input);
            }
        }
        for (dices = 0; dices < (sizeof(rolls)/sizeof(int)); dices++) {
            result += rolls[dices];
        }
    }
    printf("Your result = %d\n",result);
    return 0;
}