#include <stdio.h>
#include <string.h>
#include "manager.h"
#define MAX_USER_COMMAND_LEN 10


const char options[5][10] = {
    "Add\0","Delete\0","Edit\0","Show\0","Quit\0"
};

BOOLEAN menu(void) {
    BOOLEAN valid_command = false, running = true;
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
                    valid_command = false;
                    break;
                }
            }
            if (valid_command == true) {
                break;
            }
        }
        if (valid_command == true) {
            switch(user_command[0]) {
                case 'A': // Add staff
                    add_new_staff(); 
                    break;
                case 'D': // Delete staff (one)
                    int staff_number;
                    info("Enter the staff-number of the employee you want to delete> ");
                    scanf("%20d",&staff_number);
                    while(getchar() != '\n'); // to ignore \n
                    BOOLEAN status = delete_one_employee(staff_number);
                    if (status == true) {
                        info("Deleted staff");
                    } else {
                        // error("Couldn't delete staff"); // not neccessary
                    }
                    break;
                case 'E': // Edit staff
                    int staff_number;
                    info("Enter the staff-number of the employee you want to edit> ");
                    scanf("%20d",&staff_number);
                    while(getchar() != '\n'); // to ignore \n
                    edit_staff(staff_number);
                    break;
                case 'Q': // exit programm
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