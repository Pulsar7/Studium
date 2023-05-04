#include <stdio.h>


int main(int argc, char* argv[]) {
    int *numbers[100] = {0};
    char *operators[] = {
        '+','-','/','*','%'
    };
    int number;
    double result;
    char operator;
    printf("Geben Sie eine Zahl ein:\n");
    scanf(" %d",&result);
    while (1) {
        printf("Geben Sie einen Operator ein:\n");
        scanf(" %c",&operator);
        if (operator != 'q') {
            printf("Geben Sie eine Zahl ein:\n");
            scanf(" %d",&number);
            switch (operator) {
                case '+':
                    result = result+number;
                    break;
                case '-':
                    result = result-number;
                    break;
                case '/':
                    if (number != 0) {
                        result = result/number;
                    } else {
                        printf("Cannot divide with zero!\n");
                    }
                    break;
                case '*':
                    result = result*number;
                    break;
                case '%':
                    result = (int)result%number;
                    break;
            }
            printf(" = %f\n",result);
        } else {
            break;
        }
    }
    return 0;
}