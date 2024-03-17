#include <stdio.h>


int recursive_Fib(unsigned int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_Fib(n - 1) + recursive_Fib(n - 2);
    }
}

int iterative_Fib(unsigned int n) {
    if (n <= 1)
        return n;
    int prev1 = 0;
    int prev2 = 1;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = prev1 + prev2;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}

int main(int argc, const char **argv) {
    unsigned int n = 3;
    // a)
    printf("(Rekursiv) Fib(%d) = %d\n",n,recursive_Fib(n));
    // b)
    printf("(Iterativ) Fib(%d) = %d\n",n,iterative_Fib(n));
    return 0;
}