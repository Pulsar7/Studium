#include <stdio.h>
#include <stdlib.h>
#include "src/header.h"
#include "src/colored.h"
#include "src/database.h"


struct Command {
    int id;
    char name[20];
    char description[50];
};

struct Command commands[] = {
    {1, "help", "Shows this screen"},
    {2, "menu", "Shows the menu"}
};

void show_help(void) {
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        printf("    (%d) %s => %s\n",commands[i].id,commands[i].name,commands[i].description);
    }
}

void home(const char *db_filepath) {
    show_help();
    progress("Reading '%s'",db_filepath);
    Bool status = check_db_filepath(db_filepath);
    if (status == True) {
        status = read_db(db_filepath);
        if (status == True) {
            success();
            show_help();
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