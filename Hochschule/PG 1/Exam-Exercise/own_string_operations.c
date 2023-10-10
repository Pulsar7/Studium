#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

typedef enum {True,False} Bool;


int get_string_len(const char *string) {
    int length = 0;
    while (length < MAX_LEN) {
        if (string[length] == '\0') {
            break;
        }
        length++;
    }
    if (length == MAX_LEN) {
        length = -1;
    }
    return length;
}

Bool compare_strings(const char *string_1, const char *string_2) {
    Bool same = True;
    int string_1_len = get_string_len(string_1);
    int string_2_len = get_string_len(string_2);
    if (string_1_len < 0 || string_2_len < 0) {
        printf("One of the strings, or both, are too long or invalid!\n");
        return False;
    } else {
        for (int i = 0; i <= string_1_len; i++) {
            if (string_1[i] != string_2[i]) {
                same = False;
                break;
            }
        }
    }
    return same;
}

int main(int argc, const char **argv) {
    if (argc < 3) {
        printf("Too few arguments!\n");
        return 1;
    }
    Bool same = compare_strings(argv[1],argv[2]);
    if (same == True) {
        printf("They're the same!\n");
    } else {
        printf("They're not the same!\n");
    }
    return 0;
}