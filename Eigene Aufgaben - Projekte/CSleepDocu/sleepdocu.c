#include <stdio.h>
#include <stdlib.h>
#include "src/header.h"
#include "src/colored.h"
#include "src/database.h"
#include <string.h>
#define MAX_USER_INPUT_LEN 100


struct Command {
    char id;
    char name[20];
    char description[50];
};

struct Command commands[] = {
    {'1', "help", "Shows this screen"},
    {'2', "show-all", "Shows all sleep-entries from the database-file"},
    {'3', "exit", "Exits the program"}
};

void show_help(void) {
    info("Your options:");
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        printf("    %s(%s%c%s)%s %s => %s\n",white,blue,commands[i].id,white,reset,commands[i].name,commands[i].description);
    }
    printf("\n");
}

void home(const char *db_filepath) {
    progress("Reading '%s'",db_filepath);
    Bool status = check_db_filepath(db_filepath);
    if (status == True) {
        status = read_db(db_filepath);
        if (status == True) {
            Bool running_status = status;
            success();
            show_help();
            char user_input[MAX_USER_INPUT_LEN];
            while (running_status == True) {
                printf("%s@%s%s%s$%s>%s ",light_white,yellow,db_filepath,blue,white,reset);
                fgets(user_input,MAX_USER_INPUT_LEN,stdin);
                user_input[strlen(user_input)-1] = '\0'; // removes '\n'
                for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
                    if (strcmp(user_input, commands[i].name) == 0 || commands[i].id == user_input[0]) {
                        switch (commands[i].id) {
                            case '1':
                                show_help();
                                break;
                            case '2':
                                running_status = show_all_entries(db_filepath);
                                break;
                            case '3':
                                info("User wants to exit program");
                                running_status = False;
                                break;
                            default:
                                error("An error occured while processing the user-input!");
                                running_status = False;
                                break;
                        }
                    }
                }
            }
        } else {
            failed();
            error("Couldn't read database-file!");
        }
    } else {
        failed();
        error("Invalid database-filepath '%s'",db_filepath);
    }
}


int main(int argc, const char **argv) {
    if (argc < 2) {
        error("Invalid arguments. You have to enter a database-file!");
        return 1;
    }
    info("Started sleepdocu");
    char *db_filepath = (char*)argv[1];
    home(db_filepath);
    info("Closed sleepdocu");
    return 0;
}