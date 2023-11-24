#include <stdio.h>


int main(int argc, const char** argv) {
    // a)

    int x = 61 / 5 * 7 / (-17);
    printf("x=%d\n",x);

    // b)

    float y = 0;
    y += 61%5; // Part 1
    printf("y=%f\n",y);
    y += (61%5)*7; // Part 2
    printf("y=%f\n",y);
    y += ((61/5)*7)%(-17); // Part 3
    printf("y=%f\n",y);

    // c)

    // Written on a Unix-Based OS - Linux (Ubuntu)
    return 0;
}
