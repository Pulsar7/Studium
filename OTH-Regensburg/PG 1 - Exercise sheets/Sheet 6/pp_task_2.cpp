#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;


class DICE {
    public:
        int min_number = 1, max_number = 6, dices = 5, result = 0;
        int rolls[5] = {0};

        int roll(void) {
            if (dices > 0) {
                return ((rand()%max_number)+min_number); // pseudorandom
            } else {
                return -1;
            }
        }
};


int main(int argc, char *argv[]) {
    srand(time(NULL));
    DICE dice;
    int number;
    while (true) {
        number = dice.roll();
        if (number != -1) {
            cout << "It was the number " << number << " rolled" << endl;
            dice.rolls[5-dice.dices] = number;
            dice.dices--;
        } else {
            break;
        }
    }
    /*for (int r = 0; r < sizeof(dice.rolls)/sizeof(int); r++) {
        cout << dice.rolls[r] << endl;
    }*/

    return 0;
}