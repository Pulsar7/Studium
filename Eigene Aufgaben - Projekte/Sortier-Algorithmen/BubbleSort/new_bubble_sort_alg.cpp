#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
#define ROUNDS 1000


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


class BUBBLESORT:COLOR_PRINT {
    public:
        unsigned long int MAX_NUMBER;
        int MIN_NUMBER;
        char *filepath;

        double sort_array(char *array) {
            clock_t start, end;
            int length = strlen(array);
            double cpu_calculation_time;
            int counter = 0,current,next,not_changed = 0;
            start = clock();
            return cpu_calculation_time;
        }

    private:
        bool write_in_file(char *filepath, char *text) {
            FILE *file;
            file = fopen(filepath, "a");
            fprintf(file, text);
            fclose(file);
        }

        int pseudo_random_number(void) {
            return ((rand()%MAX_NUMBER)+MIN_NUMBER);
        }
};


int main(int argc, const char **argv) {
    srand(time(NULL));
    BUBBLESORT sort;
    sort.MAX_NUMBER = 10000000;
    sort.MIN_NUMBER = 0;
    sort.filepath = "bubble_sort_time.txt";
    
    return 0;
}