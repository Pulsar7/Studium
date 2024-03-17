#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT_LEN 100


int check_if_palindrome(char *text, int length) {
    text[length] = '\0';
    for (int i = 0; i < length; i++) {
        if (text[i] != text[length-i-1]) {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char **argv) {
    char text[MAX_TEXT_LEN];
    fgets(text,MAX_TEXT_LEN,stdin);
    int palindrome = check_if_palindrome(text,strlen(text)-1);
    if (palindrome == 1) {
        printf("'%s' is a palindrome!\n",text);
    } else {
        printf("'%s' isn't a palindrome.\n",text);
    }
    return 0;
}