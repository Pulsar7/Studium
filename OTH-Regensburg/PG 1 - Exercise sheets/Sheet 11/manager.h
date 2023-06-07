#ifndef MANAGER_H
#define MANAGER_H
#define MAX_EMPLOYEE_SURNAME_LEN 100
#define STAFF_NUMBER_LEN 20


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
BOOLEAN delete_one_employee(int staff_number);
BOOLEAN edit_staff(int staff_number);
STAFF* get_staff(int staff_number);

#endif