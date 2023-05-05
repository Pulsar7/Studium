#include <stdio.h>


int get_rek_ggt(int a, int b) {
    printf("%d, %d\n",a,b);
    if (a != b && a != 0 && b!= 0) {
        if (a > b) {
            a = a-b;
        } else {
            b = b-a;
        }
        return get_rek_ggt(a,b);
    } else {
        if (a == 0) {
            return b;
        } else {
            return a;
        }
    }
}

int get_ggt(int a, int b) {
    while (a != b && a != 0 && b != 0) {
        if (a > b) {
            a = a-b;
        } else {
            b = b-a;
        }
    }
    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

int main(int argc, char* argv[]) {
    int a = 238957, b = 3245342;
    int ggt = get_rek_ggt(a,b);
    printf("ggt(%d,%d) = %d\n",a,b,ggt);
    return 0;
}