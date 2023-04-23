#include <stdio.h>


int get_integer_input() {
    int num = 0, ch;
    do {
        ch = getchar();
        if (ch >= 48 && ch <= 57) {
            num = (num * 10 + (ch - 48)); // convert to digit
        } else if ((int)ch != 10) { // checks if ASCII-Code of character is not ' ' (found deviant!)
            num = -1;
            break;
        }
        if (ch == '\n') {
            break;
        }
    } while (1);
    return num;
}


int main(int argc, char* argv[]) {
    int n,f = 0;
    printf("Please enter the upper-limit:\n");
    n = get_integer_input();
    if (n != -1) {
        for (int i = 0; i <= n; i++) {
            f += (2*i+3);
        }
        printf("f = %d\n",f);
    } else {
        printf("Enterd invalid number!\n");
    }
    return 0;
}