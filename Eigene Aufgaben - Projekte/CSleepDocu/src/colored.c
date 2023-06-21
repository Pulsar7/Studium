#include "colored.h"
#include <stdarg.h>
#include <stdio.h>


// color declaration
char white[MAX_COLOR_LEN] = "\x1b[37m";
char red[MAX_COLOR_LEN] = "\x1b[31m";
char blue[MAX_COLOR_LEN] = "\x1b[94m";
char reset[MAX_COLOR_LEN] = "\x1b[39m";
char yellow[MAX_COLOR_LEN] = "\x1b[33m";
char light_white[MAX_COLOR_LEN] = "\x1b[97m";
char light_red[MAX_COLOR_LEN] = "\x1b[91m";
//


void progress(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("%s[%sINFO%s]%s ",white,yellow,white,reset);
    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, char);
                    printf("%s%c%s",light_white,c,reset);
                    break;
                }
                case 's': {
                    char* str = va_arg(args, char*);
                    printf("%s%s%s",light_white,str,reset);
                    break;
                }
                default:
                    printf("Unknown placeholder: %%%c", *format);
                    break;
            }
        } else {
            printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    printf("%s...",reset);
}


void info(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("%s[%sINFO%s]%s ",white,yellow,white,reset);
    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    printf("%s%c%s",light_white,c,reset);
                    break;
                }
                case 's': {
                    char* str = va_arg(args, char*);
                    printf("%s%s%s",light_white,str,reset);
                    break;
                }
                default:
                    printf("Unknown placeholder: %%%c", *format);
                    break;
            }
        } else {
            printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    printf("\n");
}

void error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("%s[%sERROR%s]%s ",white,red,white,red);
    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    printf("%s%c%s",light_red,c,red);
                    break;
                }
                case 's': {
                    char* str = va_arg(args, char*);
                    printf("%s%s%s",light_red,str,red);
                    break;
                }
                default:
                    printf("Unknown placeholder: %%%c", *format);
                    break;
            }
        } else {
            printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    printf("\n");
}

void failed(void) {

}

void success(void) {

}