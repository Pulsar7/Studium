#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "manager.h"
#define MAX_USER_COMMAND_LEN 10


const char options[6][10] = {
    "Add\0","Delete\0","Edit\0","Show\0","Help\0","Quit\0"
};


BOOLEAN menu(void) {
    BOOLEAN valid_command = false, running = true;
    int staff_number;
    char user_command[MAX_USER_COMMAND_LEN];
    info("Enter your command:");
    fgets(user_command,MAX_USER_COMMAND_LEN,stdin);
    user_command[strlen(user_command)-1] = '\0';
    if (strlen(user_command) > 0) {
        for (int i = 0; i < 6; i++) {
            for (int e = 0; e < strlen(options[i]); e++) {
                if (options[i][e] == user_command[e]) {
                    valid_command = true;
                } else {
                    if (e == 0 && tolower(options[i][e]) == user_command[e]) {
                        valid_command = true;
                    } else {
                        valid_command = false;
                        break;
                    }
                }
            }
            if (valid_command == true) {
                break;
            }
        }
        if (valid_command == true) {
            switch(user_command[0]) {
                case 'A': case 'a': // Add staff
                    add_new_staff(); 
                    break;
                case 'D': case 'd': // Delete staff (one)
                    info("Enter the staff-number of the employee you want to delete> ");
                    scanf("%20d",&staff_number);
                    while(getchar() != '\n'); // to fetch the '\n'
                    BOOLEAN status = delete_one_employee(staff_number);
                    if (status == true) {
                        info("Deleted staff");
                    } else {
                        // error("Couldn't delete staff"); // not neccessary
                    }
                    break;
                case 'E': case 'e':// Edit staff
                    edit_staff();
                    break;
                case 'S': case 's': // Show all employees
                    show_all_employees();
                    break;
                case 'H': case 'h': // Show all options
                    show_help(options);
                    break;
                case 'Q': case 'q': // exit programm
                    running = false;
                    info("User wants to exit programm");
                    break;
                default:
                    info("Invalid option!");
                    running = false;
                    break;
            }
        } else {
            char error_msg[200] = " => is an invalid option!";
            strcat(user_command,error_msg);
            error(user_command);
        }
    } else {
        // empty
    }
    return running;
}



int main(int argc, const char **argv) {
    BOOLEAN running = true;
    info("Started programm.");
    while (running == true) {
        running = menu();
    }
    running = delete_all_employees(); // free HEAP
    info("Closed programm.");
    return 0;
}