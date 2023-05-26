#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;


class COLOR_PRINT {
    public:
        string white = "\x1b[37m", red = "\x1b[31m", green = "\x1b[32m",
            yellow = "\x1b[33m", reset = "\x1b[39m";

        void info(string text) {
            cout << white+"["+yellow+"INFO"+white+"] "+reset+text << endl;
        }

        void error(string text) {
            cout << white+"["+red+"ERROR"+white+"] "+reset+text << endl;
        }

        void progress(string text) {
            cout << white+"["+yellow+"INFO"+white+"] "+reset+text;
        }

        void success(void) {
            cout << green+"O.K." << endl;
        }

        void failed(void) {
            cout << red+"FAILED" << endl;
        }
};

class ENCRYPTER:COLOR_PRINT {
    public:
        int public_key[2] = {0}, private_key[2] = {0};

        bool create_key_pair(void) {
            bool status = true;
            long int p, q;
            while (1) {
                p = pseudo_random_number();
                q = pseudo_random_number();
                status = divider_extraneous(p,q);
                if (status == true) {
                    break;
                }
            }
            // info("Found two numbers: p="+to_string(p)+" and q="+to_string(q));

            return status;
        }

    private:
        int pseudo_random_number(void) {
            return ((rand()%10)+0);
        }

        bool divider_extraneous(int number_one, int number_two) { // Euclidean algorithm
            bool status = false;
            do {
                if (number_one > number_two) {
                    number_one -= number_two;
                }
                if (number_two > number_one) {
                    number_two -= number_one;
                }
            } while(number_one != number_two && number_one != 0 && number_two != 0 && (number_one == 1 || number_two == 1));
            if (number_one == 1 || number_two == 1) {
                status = true;
            }
            return status;
        }
};



int main(int argc, const char **argv) {
    srand(time(NULL));
    COLOR_PRINT cprint;
    ENCRYPTER encryption;
    cprint.progress("Generating key-pair...");
    if (encryption.create_key_pair() == true) {
        cprint.success();
    } else {
        cprint.failed();
    }
    return 0;
}