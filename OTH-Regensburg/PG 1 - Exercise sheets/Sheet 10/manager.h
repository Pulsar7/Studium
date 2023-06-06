#ifndef MANAGER_H
#define MANAGER_H
#define MAX_EMPLOYEE_SURNAME_LEN 100
#define STAFF_NUMBER_LEN 20


int list_elements = 0;
STAFF *current_pointer = NULL, *head_pointer;

// constants
const char *white = "\x1b[37m", *green = "\x1b[32m", 
    *yellow = "\x1b[33m", *reset = "\x1b[39m", *red = "\x1b[31m";

const char options[5][10] = {
    "Add","Delete","Edit","Show","Quit"
};

// colored-output - Functions
void info(char *message);
void error(char *message);
void success(void);
void failed(void);
void progress(char *message);

// "database"-Functions
BOOLEAN add_new_staff(void);
int generate_staff_number(void);
BOOLEAN check_if_staff_number_exists(int staff_number);
BOOLEAN delete_all_employees(void);

// enumerations
typedef enum {true=1,false=0} BOOLEAN;

// structs
typedef struct STAFF {
    char surname[MAX_EMPLOYEE_SURNAME_LEN];
    float salary;
    int staff_number;
    struct STAFF *next;
    struct STAFF *previous;
} STAFF;

#endif