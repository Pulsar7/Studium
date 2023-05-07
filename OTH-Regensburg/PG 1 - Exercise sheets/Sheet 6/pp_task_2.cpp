#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#define MAX_ROUNDS 3


class COLORED_OUTPUT {
    public:
        string white = "\x1b[37m", red = "\x1b[31m", blue = "\x1b[94m", yellow = "\x1b[93m", reset = "\x1b[39m";
    
        string info(string text) {
            return white+"["+yellow+"INFO"+white+"] "+text+reset;
        } 

        string error(string text) {
            return white+"["+red+"ERROR"+white+"] "+red+text+reset;
        }
};


class DICE {
    public:
        int min_number = 1, max_number = 6, result = 0;
        int rolls[5] = {0};

        int roll(void) {
            return ((rand()%max_number)+min_number); // pseudorandom
        }
};


int main(int argc, char *argv[]) {
    srand(time(NULL));
    DICE dice;
    COLORED_OUTPUT co;
    int number, dices, max_dices = 5, user_input;
    bool valid_input = true;
    for (int rounds = 0; rounds < MAX_ROUNDS; rounds++) {
        for (dices = 0; dices < max_dices; dices++) {
            dice.rolls[dices] = dice.roll();
            cout << co.info(to_string(dices)+" -> number: "+to_string(dice.rolls[dices])) << endl;
        }
        while (max_dices > 1) {
            cout << co.info("Enter the dices to delete (enter -1 to end): ") << endl;
            cin >> user_input;
            if ((user_input < 5 && user_input >= 0) || user_input == -1) {
                if (user_input != -1) {
                    dice.rolls[user_input] = 0;
                    max_dices--;
                } else {
                    break;
                }
            } else {
                cout << co.error("The number "+to_string(user_input)+" is invalid!") << endl;
            }
        }
        for (dices = 0; dices < (sizeof(dice.rolls)/sizeof(int)); dices++) {
            dice.result += dice.rolls[dices];
            cout << dice.result << endl;
        }
    }
    cout << co.info("Your result = "+to_string(dice.result)) << endl;
    return 0;
}