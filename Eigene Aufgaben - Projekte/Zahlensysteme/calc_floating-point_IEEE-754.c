#include <stdio.h>
#include "src/logger.h"
#include <math.h>
#include <stdlib.h>


void signed_bit(float user_input, char* complete_number) {
    if (user_input < 0) {
        complete_number[0] = '1';
    }
}

void convert_int_decimal_to_binary(char* number_in_binary, int number) {
    char decimal_char_number[sizeof(int)*8];
    char* rest = (char*)malloc(sizeof(int)*8);
    BOOLEAN need_twos_complement = false;
    if (rest != NULL) {
        if (number < 0) {
            number = -(number); // Make the number positive
            need_twos_complement = true;
        }
        printf("NUMBER: %d\n",number);
        if (need_twos_complement == true) {
            printf("Two's complement!");
        }
    } else {
        printf("Space-allocation failed with malloc\n");
        return;
    }

    int current_rest = 0;
    int quotient = number;
    int counter = 0;
    while (quotient > 0) {
        quotient = quotient/2;
        rest[((sizeof(int)*8)-1)-counter] = '\0';
        counter++;
    }

    printf("%s\n",rest);
}

void calc_binary_number(float user_input, char* complete_number) {
    double integer_part;
    double floating_point_part = modf(user_input, &integer_part);
    char number_in_binary[sizeof(int)*8];
    if (floating_point_part == 0.0) { // Number is an integer
        convert_int_decimal_to_binary(number_in_binary,(int)user_input);
    } else {
        // converting integer-part to binary
        // -> integer_part
        char integer_part_in_binary[sizeof(int)*8];
        convert_int_decimal_to_binary(integer_part_in_binary,(int)user_input);
        // converting floating-point-part to binary
        // -> floating_point_part
        char char_fractional_part_num[32];
        snprintf(char_fractional_part_num, sizeof(char_fractional_part_num), "%f", floating_point_part);
        printf("%s\n",char_fractional_part_num);
    }
}

int main(int argc, const char** argv) {
    float user_input;
    scanf("%40f",&user_input);
    char complete_number[40]; // = "0 00000000 00000000000000000000000";
    for (int i = 0; i < 40; i++) { 
        if (i == 0 || (i > 1 && i < 10) || (i > 10 && i < 39)) {
            complete_number[i] = '0';
        } else {
            complete_number[i] = ' ';
        }
    }
    info(complete_number);

    signed_bit(user_input,complete_number);
    calc_binary_number(user_input,complete_number);

    info(complete_number);
    return 0;
}