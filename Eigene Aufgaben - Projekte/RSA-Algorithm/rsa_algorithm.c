#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_MSG_LEN 100
#define MAX_NUMBER 10000000
#define MIN_NUMBER 0


long int pseud_rand_number(void) {
    return ((rand()%MAX_NUMBER)+MIN_NUMBER);
}


long int choose_prime_number(void) {
    long int prime_number,random_number;
    do {
        random_number = pseud_rand_number();
        // 
    } while (1);
    return prime_number;
}

long int choose_e(long int m) {
    long int e;
    do {

    } while(1);
}

int generate_key_pair(long int *private_key, long int *public_key) {
    long int p = choose_prime_number(), q = choose_prime_number();
    long int n = p*q;
    long int e = choose_e((p-1)*(q-1));
    return 0;
}


int main(int argc, const char **argv) {
    srand(time(NULL));
    char msg[MAX_MSG_LEN];
    long int private_key[2] = {0}, public_key[2] = {0};
    fgets(msg,MAX_MSG_LEN,stdin);
    char encrypted_msg[strlen(msg)];
    generate_key_pair(private_key,public_key);
    printf("Your message: %s\n",msg);
    return 0;
}