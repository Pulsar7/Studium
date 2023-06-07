#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#define MAX_NUMBER 100000000

// 
int list_elements = 0;
STAFF *current_pointer = NULL, *head_pointer;

const char *white = "\x1b[37m", *green = "\x1b[32m", 
    *yellow = "\x1b[33m", *reset = "\x1b[39m", *red = "\x1b[31m";

void info(char *message) {
    printf("%s[%sINFO%s]%s %s\n",white,yellow,white,reset,message);
}

void error(char *message) {
    printf("%s[%sERROR%s]%s %s\n",white,red,white,reset,message);
}

void success(void) {
    printf("%sO.K.%s\n",green,reset);
}

void failed(void) {
    printf("%sFAILED%s\n",red,reset);
}

void progress(char *message) {
    printf("%s[%sINFO%s]%s %s",white,yellow,white,reset,message);
}

//

STAFF* create_first_staff(char *surname, float salary,  int staff_number) {
    STAFF* head_pointer = (STAFF*)malloc(sizeof(STAFF));
    if (head_pointer != NULL) {
        strcpy(head_pointer->surname, surname);
        head_pointer->salary = salary;
        head_pointer->staff_number = staff_number;
        head_pointer->next = NULL;
        head_pointer->previous = NULL;
    }
    return head_pointer;
}

STAFF* create_staff(char *surname, float salary, int staff_number) {
    // always adds staff at the bottom of list
    STAFF* current = current_pointer;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (STAFF*)malloc(sizeof(STAFF));
    if (current->next != NULL) {
        current->next->next = NULL;
        current->next->previous = current;
        strcpy(current->next->surname, surname);
        current->next->salary = salary;
        current->next->staff_number = staff_number;
    }
    return current->next;
}

BOOLEAN edit_staff(int staff_number) {
    BOOLEAN status;
    if (list_elements > 0) {
        if (check_if_staff_number_exists(staff_number) == true) {
            STAFF *staff_pointer = get_staff(staff_number);
            if (staff_pointer != NULL) {
                progress("Editing staff...");

                success();
            } else {
                error("Staff-Pointer is NULL!");
                status = false;
            }
        } else {
            failed();
            error("There is no employee with that staff-number!");
            status = false;
        }
    } else {
        status = false;
        info("There are no employees to edit. Linked list is empty!");
    }
    return status;
}

STAFF* get_staff(int staff_number) { // probably the same as 'check_if_staff_exists'
    BOOLEAN found = false;
    STAFF *staff_pointer;
    STAFF *current = head_pointer;
    while (current != NULL) {
        if (current->staff_number == staff_number) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) {
        staff_pointer = NULL;
    }
    return staff_pointer;
}

BOOLEAN delete_all_employees(void) {
    BOOLEAN status;
    if (list_elements > 0) {
        STAFF *current = head_pointer;
        while (current->next != NULL) {
            status = delete_one_employee(current->staff_number);
            if (status == false) {
                break;
            }
            current = current->next;
        }
    } else {
        status = false;
        info("There are no employees to delete. Linked list is empty!");
    }
    return status;
}

BOOLEAN delete_one_employee(int staff_number) {
    BOOLEAN status = true;
    progress("Deleting employee...");
    if (check_if_staff_number_exists(staff_number) == true) {
        STAFF *current = head_pointer;
        while (current != NULL) {
            if (current->staff_number == staff_number) {
                break;
            }
            current = current->next;
        }
        if (current != NULL) {
            if (current->next == NULL) { // last element of list
                current->previous->next = NULL;
            } else if(current->previous == NULL) { // first element of list
                current->next->previous = NULL;
            } else { // between two elements in list
                current->next->previous = current->previous;
                current->previous->next = current->next;
            }
            free(current);
            list_elements--;
        } else {
            failed();
            error("An error occured while trying to get pointer of staff-member in linked list!");
            status = false;
        }
    } else {
        failed();
        error("There is no employee with that staff-number!");
        status = false;
    }
    return status;
}

BOOLEAN check_if_staff_number_exists(int staff_number) {
    // checks if staff-number exists
    BOOLEAN exists = false;
    STAFF* current = head_pointer;
    while (current != NULL) {
        if (current->staff_number == staff_number) {
            exists = true;
            break;
        }
        current = current->next;
    }
    return exists;
}

int generate_pseud_rand(void) {
    // generates staff-number
    return ((rand()%MAX_NUMBER)+0);
}

int generate_staff_number(void) {
    srand(time(NULL));
    int staff_number;
    while (1) {
        staff_number = generate_pseud_rand();
        if (check_if_staff_number_exists(staff_number) == false) {
            break;
        }
    }
    return staff_number;
}

BOOLEAN add_new_staff(void) {
    BOOLEAN status = true;
    char surname[MAX_EMPLOYEE_SURNAME_LEN];
    info("Enter his/her surname> ");
    fgets(surname,MAX_EMPLOYEE_SURNAME_LEN,stdin);
    progress("Adding new staff member...");
    float salary;
    scanf("%20f", &salary); // 20 is probably to large...
    if (salary < 0) {
        failed();
        error("You entered an invalid salary!");
        return false;
    }
    if (salary > 100000) {
        failed();
        error("Then our company would be broke...");
        return false;
    }
    info("Enter his/her salary> ");
    if (list_elements == 0) {
        current_pointer = create_first_staff(surname,salary,generate_staff_number());
    } else if (list_elements > 0) {
        current_pointer = create_staff(surname,salary,generate_staff_number());
    }
    if (current_pointer == NULL) {
        failed();
        error("Got a NULL-Pointer as return argument from 'malloc'!");
    } else {
        success();
        if (list_elements == 0) {
            head_pointer = current_pointer;
        }
        list_elements++;
    }
    return status;
}