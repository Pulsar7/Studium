#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_ARR_LEN 100


int check_if_sentence_palindrome(char *text, int length) {
    char crushed_text[length];
    int counter = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i]) != 0) {
            crushed_text[counter] = text[i];
            counter++;
        }
    }
    printf("%s\n",crushed_text);
    return 1;
}


int main(int argc, const char **argv) {
    char text[MAX_ARR_LEN];
    fgets(text,MAX_ARR_LEN,stdin);
    int palindrome = check_if_sentence_palindrome(text,strlen(text)-1);
    if (palindrome == 1) {
        printf("'%s' is a sentence-palindrome!\n",text);
    } else {
        printf("'%s' isn't a sentence-palindrome.\n",text);
    }
    return 0;
}