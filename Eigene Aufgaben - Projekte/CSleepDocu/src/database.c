#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include "database.h"
#include "colored.h"


SleepEntry *head_pointer = NULL;


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
    FILE *file = fopen(db_filepath, "r");
    if (file == NULL) {
        return False;
    }
    /*
    char buffer[100]; // Create a buffer to store the read data
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Process the read line
        printf("%s", buffer);
    }
    */
    fclose(file);
    return True;
}

Bool add_entry_to_list(char *sleep_id, char *date, Mood sleepy_mood, Mood rising_mood, Bool wet_bed, 
    Location location, char *bedtime, char *risetime, char *notes, Bool drank_a_lot_before_bedtime, 
    Bool stress_before_bedtime, Bool sick_to_bed, Bool memory_of_dream) {
    progress("Adding new element to list...");
    if (head_pointer == NULL) {
        // first object in list
        head_pointer = (SleepEntry*)malloc(sizeof(SleepEntry));
    }
    // iterates to the end of the list
    SleepEntry *current = head_pointer;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (SleepEntry*)malloc(sizeof(SleepEntry));
    if (head_pointer != NULL) {
        head_pointer->next = NULL;
        head_pointer->previous = NULL;
        strcpy(head_pointer->sleep_id,sleep_id);
        strcpy(head_pointer->bedtime,bedtime);
        strcpy(head_pointer->date,date);
        strcpy(head_pointer->risetime,risetime);
        strcpy(head_pointer->notes,notes);
        head_pointer->stress_before_bedtime = stress_before_bedtime;
        head_pointer->sick_to_bed = sick_to_bed;
        head_pointer->memory_of_dream = memory_of_dream;
        head_pointer->rising_mood = rising_mood;
        head_pointer->wet_bed = wet_bed;
        head_pointer->location = location;
    } else {
        failed();
        error("Couldn't add new element to list, because the malloc function returned a NULL-Pointer!");
        return False;
    }
    success();
    return True;
}

Bool show_all_entries(const char *db_filepath) {
    progress("Opening database-file");
    FILE *file = fopen(db_filepath, "r");
    if (file == NULL) {
        failed();
        return False;
    }
    success();
    char buffer[READ_FILE_LINE_LEN];
    Bool status;
    char sleep_id[SLEEP_ID_LEN];
    char date[MAX_DATE_LEN];
    Mood sleepy_mood;
    Mood rising_mood;
    Bool wet_bed;
    Location location;
    char bedtime[MAX_BEDTIME_LEN];
    char risetime[MAX_RISETIME_LEN]; // wake_up_time
    char notes[MAX_NOTES_LEN];
    Bool drank_a_lot_before_bedtime;
    Bool stress_before_bedtime;
    Bool sick_to_bed;
    Bool memory_of_dream;
    SleepEntry *next;
    SleepEntry *previous;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int r = 0; r < READ_FILE_LINE_LEN; r++) {
            // iterates line to get all arguments of sleep-entry
            if (buffer[r] == ';') {
                // new element
            } else {
                    
            }
        }
        /*status = add_entry_to_list(sleep_id, date, sleepy_mood, rising_mood, wet_bed, 
            location, bedtime, risetime, notes, drank_a_lot_before_bedtime, stress_before_bedtime, sick_to_bed,
            memory_of_dream);*/
        if (status == False) {
            return False;
        }
    }
    fclose(file);
    return True;
}