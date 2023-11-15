#include <stdio.h>
#include <string.h>

void info(const char* msg) {
    printf("<INFO> %s\n",msg);
}

void warning(const char* msg) {
    printf("<WARNING> %s\n",msg);
}

void error(const char* msg) {
    printf("<ERROR> %s\n",msg);
}

void progress(const char* msg) {
    printf("<INFO> %s...",msg);
}

void ok(const char* msg) {
    if (strlen(msg) > 0) {
        printf("%s\n",msg);
    } else {
        printf("O.K.");
    }
}

void failed(const char* msg) {
    if (strlen(msg) > 0) {
        printf("%s\n",msg);
    } else {
        printf("O.K.");
    }
}