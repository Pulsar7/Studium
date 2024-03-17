#include <stdio.h>


int main(int argc, char* argv[]) {
    int a1,a0,b1,b0,s1 = 0,s0 = 0,u = 0;
    scanf("%d %d %d %d",&a1,&a0,&b1,&b0);
    if ((a1 == 0 || a1 == 1) && (b1 == 0 || b1 == 1) && (a0 == 0 || a0 == 1) && (b0 == 0 || b0 == 1)) {
        if (a0 == 1 && b0 == 1) {
            s1++;
        }
        if ((a0 == 0 && b0 == 1) || (a0 == 1 && b0 == 0)) {
            s0++;
        }
        if (a1 == 1 && b1 == 1) {
            u++;
        }
        if ((a1 == 1 && b1 == 0) || (a1 == 0 && b1 == 1)) {
            if (s1 > 0) {
                u++;
                s1 = 0;
            } else {
                s1++;
            }
        }
        if (u > 0) {
            printf("%d%d%d\n",u,s1,s0);
        } else {
            printf("%d%d\n",s1,s0);
        }
    } else {
        printf("Invalid input!\n");
    }
    return 0;
}