#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT_LEN 100


void swap_text(char *text, char *swapped_text) {
    int length = strlen(text)-1;
    for (int i = 0; i < length; i++) {
        swapped_text[i] = text[length-1-i];
    }
    swapped_text[length] = '\0';
}


int main(int argc, char **argv) {
    char text[MAX_TEXT_LEN];
    fgets(text, MAX_TEXT_LEN, stdin);
    char swapped_text[strlen(text)-1];
    swap_text(text,swapped_text);
    printf("Your Text: %s | Swapped Text: %s\n",text,swapped_text);
    return 0;
}