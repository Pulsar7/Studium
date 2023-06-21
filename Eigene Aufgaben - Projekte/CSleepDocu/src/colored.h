#ifndef COLORED_H
#define COLORED_H
#define MAX_COLOR_LEN 10



// colors
extern char white[MAX_COLOR_LEN];
extern char red[MAX_COLOR_LEN];
extern char green[MAX_COLOR_LEN];
extern char blue[MAX_COLOR_LEN];
extern char reset[MAX_COLOR_LEN];
extern char yellow[MAX_COLOR_LEN];
extern char light_white[MAX_COLOR_LEN];
extern char ligh_red[MAX_COLOR_LEN];


// functions
void info(const char* format, ...);
void error(const char* format, ...);
void progress(const char* format, ...);
void failed(void);
void success(void);

#endif