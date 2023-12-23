#include <stdio.h>

int add_function(int x, int y) {
    return x + y;
}

int main(int argc, const char** argv) {
    int result;
    int x = 1;
    int y = 2;
    result = add_function(x,y);
    printf("The result is: %d\n", result);
    return 0;
}