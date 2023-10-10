#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_TEXT_LEN 100


typedef enum {True=1,False=0} BOOLEAN;


BOOLEAN check_if_palindrome(char *text, int length) {
    text[length] = '\0';
    char *start = text;
    char *end = text;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        while (! isalpha(*start)) {
            start++;
        }
        while (! isalpha(*end)) {
            end--;
        }
        if (tolower(*start) != tolower(*end)) {
            return False;
        }

        start++;
        end--;
    }
    return True;
}


int main(int argc, char **argv) {
    char text[MAX_TEXT_LEN];
    fgets(text,MAX_TEXT_LEN,stdin);
    int palindrome = check_if_palindrome(text,strlen(text)-1);
    if (palindrome == True) {
        printf("'%s' is a palindrome!\n",text);
    } else {
        printf("'%s' isn't a palindrome.\n",text);
    }
    return 0;
}