#include <stdio.h>


int get_integer_input() {
    int num = 0, ch;
    do {
        ch = getchar();
        if (ch >= 48 && ch <= 57) {
            num = (num * 10 + (ch - 48)); // convert to digit
        } else if ((int)ch != 10) { // checks if ASCII-Code of character is not ' ' (found deviant!)
            num = -1;
            break;
        }
        if (ch == '\n') {
            break;
        }
    } while (1);
    return num;
}


int main(int argc, char* argv[]) {
    int day,month,year,w;
    char weekdays[7][9] = {
        "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
    };
    printf("Enter the day:\n");
    day = get_integer_input();
    if (day != -1 && day >= 1 && day <= 31) {
        printf("Enter the month:\n");
        month = get_integer_input();
        if (month != -1 && month <= 12 && month >= 1 && (month != 2 || day <= 29)) {
            printf("Enter the year:\n");
            year = get_integer_input();
            if (year >= 1582) {
                int m = month, y = year;
                if (month <= 2) {
                    m += 12;
                    y -= 1;
                }
                w = ((day+2*m+(3*m+3)/5+y+y/4-y/100+y/400+1)%7);
                printf("The %d.%d.%d is a %s.\n",day,month,year,weekdays[w]);
            } else {
                printf("The given year is invalid!\n");
            }
        } else {
            printf("The given month is invalid!\n");
        }
    } else {
        printf("The given day is invalid!\n");
    }
    return 0;
}