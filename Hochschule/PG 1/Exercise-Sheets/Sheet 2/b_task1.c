#include <stdio.h>

int main(int argc, char* argv[]) {
    char elements[] = {
        '0','1','2','3','4','6','7','8','9','\0'
    };
    for (int i = 0; i < 10; i++) {
        printf("%c = %d\n",elements[i],elements[i]);
    }
    return 0;
}