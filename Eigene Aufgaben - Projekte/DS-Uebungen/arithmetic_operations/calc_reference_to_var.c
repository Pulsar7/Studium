#include <stdio.h>


int add_func(int x, int y, int z) {
    printf("Added %d + %d\n",z,y);
    return z + y;
}

int sub_func(int x, int y, int z) {
    printf("Subtracted %d - %d\n",z,y);
    return z - y;
}

void calc_func(int x, int y, int z) {
    int result;
    if (y >= x) {
        result = add_func(x,y,z);
    } else {
        result = sub_func(x,y,z);
    }
    printf("x=%d y=%d z=%d » The result is: %d «\n",x,y,z,result);
}

int main(int argc, const char** argv) {
    int x = 1, y = 2, z = 3;
    calc_func(x, y, z);
    return 0;
}