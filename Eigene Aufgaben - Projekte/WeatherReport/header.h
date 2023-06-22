#ifndef HEADER_H
#define HEADER_H
#define MAX_SOURCE_NAME_LEN 100
#define MAX_SOURCE_URL_LEN 100
#define MAX_BUFFER_SIZE 2048
#define MAX_REQUEST_LEN 200
#define MAX_SOURCE_HOST_LEN 20


typedef enum {True,False} Bool;

typedef struct Source {
    char name[MAX_SOURCE_NAME_LEN];
    char host[MAX_SOURCE_HOST_LEN];
    char url[MAX_SOURCE_URL_LEN];
    int port;
} Source;

#endif