#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EXAMPLES 10
#define RANGE_MIN 0
#define RANGE_MAX 9

int calc_first(int x) {
    return (2*x*x+3*x+17);
}

int calc_second(int a, int b, int c, int d) {
    int result;
    int z = (a - 3);
    int divide = ((d+3)*(d+3)*(d+3));
    if (divide < 0) {
        int n = (b + 2*(c/divide));
        if (n != 0) {
            result = (z / n);
        } else {
            result = 0;
            printf("Mathematical error! (Division with zero)\n");
        }
    } else {
        result = 0;
        printf("Mathematical error! (Division with zero)\n");
    }
    // printf("a = %d | b = %d | c = %d | d = %d\n",a,b,c,d);
    return result;
}

int generate_pseud_rand_number() {
	return RANGE_MIN+(rand()%(RANGE_MAX-RANGE_MIN));
}

int main(int argc, int* argv[]) {
    srand(time(NULL)); // set seed
    unsigned int first_result,second_result;
    /*for (int i = 0; i < EXAMPLES; i++) {
        first_result = calc_first(generate_pseud_rand_number());
        second_result = calc_second(
            generate_pseud_rand_number(),
            generate_pseud_rand_number(),
            generate_pseud_rand_number(),
            generate_pseud_rand_number()
        );
        printf("(1) = %d | (2) = %d\n",first_result,second_result);  
    }*/
    first_result = calc_first(1);
    second_result = calc_second(0,1,2,-3);
    printf("(1) = %d | (2) = %d\n",first_result,second_result);
    printf("Result: %.20f \n",(float)(4.4444*3.333));
    return 0;
}