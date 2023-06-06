#include <stdio.h>
#include <string.h>
#include "manager.h"
#define MAX_USER_COMMAND_LEN 10


BOOLEAN menu(void) {
    BOOLEAN valid_command = false;
    char user_command[MAX_USER_COMMAND_LEN];
    info("Enter your command:");
    fgets(user_command,MAX_USER_COMMAND_LEN,stdin);
    // int command_len = strlen(user_command);
    for (int i = 0; i < 6; i++) {
        if (options[i] == user_command) {
            valid_command = true;
            break;
        }
    }
    if (valid_command == true) {
        switch(user_command[0]) {
            case 'A': // Add staff
                add_new_staff(); 
                break;
            case 'D': // Delete staff
                break;
            case 'E': // Edit staff
                break;
            case 'Q': // exit programm
                valid_command = false; 
                info("User wants to exit programm");
                break;
        }
    } else {
        char error_msg[200] = " => is an invalid option!";
        strcat(user_command,error_msg);
        error(user_command);
    }
    return valid_command;
}



int main(int argc, const char **argv) {
    BOOLEAN running = true;
    while (running == true) {
        running = menu();
    }
    info("Closed programm.");
    return 0;
}