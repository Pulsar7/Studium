#include <stdio.h>
#include <stdlib.h>
#include "src/header.h"
#include "src/colored.h"
#include "src/database.h"


void home(const char *db_filepath) {
    Bool status = check_db_filepath(db_filepath);
    if (status == True) {

    } else {
        error("Invalid database-filepath '%s'",db_filepath);
    }
}


int main(int argc, const char **argv) {
    if (argc < 2) {
        error("Invalid arguments. You have to enter a database-file!");
        return 1;
    }
    char *db_filepath = (char*)argv[1];
    home(db_filepath);
    info("Closed sleepdocu");
    return 0;
}