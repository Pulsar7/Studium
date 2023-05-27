/*
    New version of the "A.M.M.E. - Encryption"
*/
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
using namespace std;
#define MAX_NUMBER 10000000
#define MIN_NUMBER 0


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


class ENCRYPTION:COLOR_PRINT {
    public:
        int key_length;
        string key;
        char all_characters[52] = {
            'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
            'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
        };
        int vectors[52][2];

        bool generate_key(void) {
            
        }

    private:
        int pseudo_random_number(void) {
            return ((rand()%MAX_NUMBER)+MIN_NUMBER);
        }

};


int main(int argc, const char **argv) {
    srand(time(NULL));
    ENCRYPTION encryption;
    COLOR_PRINT cp;
    encryption.key_length = 100;
    
    return 0;
}