#include <stdio.h>

int get_input(char user_input[], char vocabular[]) {
    int state = 0, counter = 0;
    char ch;
    do {
        ch = getchar();
        state = 1;
        for (int i = 0; i < 2; i++) {
            if (ch == vocabular[i]) {
                state = 0;
                break;
            }
        }
        if (state == 1 || ch == '\n') {
            break;
        }
        user_input[counter] = ch;
        counter++;
    } while (1);
    return state;
}

int main(int argc, char* argv[]) {
    char user_input[100] = {};
    char vocabular[] = {'a','b','\0'};
    int state = get_input(user_input,vocabular);
    if (state == 0) {
        printf("User-input: %s\n",user_input);
        
    } else {
        printf("You entered an invalid character which is not in the vocabular: %s\n",vocabular);
    }
    return 0;
}