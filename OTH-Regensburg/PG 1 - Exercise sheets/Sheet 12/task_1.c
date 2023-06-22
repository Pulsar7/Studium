#include <stdio.h>

int main() {
    unsigned char ZUSTAND = 0x82; // Bsp. -> PWR-Bit = 1;

    if (ZUSTAND & 0x80) {
        printf("ON\n");
    } else {
        printf("OFF \n");
    }

    int R = (ZUSTAND & 0x20) ? 1 : 0;
    int B = (ZUSTAND & 0x02) ? 1 : 0;

    return 0;
}