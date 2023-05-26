#include <iostream>
#include <time.h>
#include <string>
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


class ENCRYPTION:COLOR_PRINT {
    public:
        int key_length;
        string key;

        bool generate_key(void) {

        }

};


int main(int argc, const char **argv) {
    ENCRYPTION encryption;
    COLOR_PRINT cp;
    encryption.key_length = 100;
    
    return 0;
}