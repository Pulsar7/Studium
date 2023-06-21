#include <stdio.h>
#include <string.h>
#include "header.h"
#include "database.h"


Bool check_db_filepath(const char *db_filepath) {
    /*
        Checks if last three elements of filepath are '.sdb'
    */
    int filepath_len = strlen(db_filepath)-1;
    if (db_filepath[filepath_len-3] == '.') {
        if (db_filepath[filepath_len-2] == 's') {
            if (db_filepath[filepath_len-1] == 'd') {
                if (db_filepath[filepath_len] == 'b') {
                    return True;
                }
            }
        }
    }
    return False;
}

Bool read_db(const char *db_filepath) {
    return True;
}