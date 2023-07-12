#include <stdio.h>

int main(int argc, char* argv[]) {
    int a = 12.9;
    printf("%d und %f\n",a,(float)a);
    float b = 4.3;
    float c = 12.5;
    b = b + c / (float)a;

    printf("Ergebnis: %f \n", b);

    return 0;
}