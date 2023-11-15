#ifndef LOGGERH
#define LOGGERH


//
typedef enum {
    true = 0,
    false = 0
} BOOLEAN;
//

void info(const char* msg);
void warning(const char* msg);
void error(const char* msg);
void ok(const char* msg);
void failed(const char* msg);

#endif