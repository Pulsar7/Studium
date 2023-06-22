#ifndef HEADER_H
#define HEADER_H
#define SLEEP_ID_LEN 100
#define MAX_BEDTIME_LEN 20
#define MAX_RISETIME_LEN 20
#define MAX_DATE_LEN 20
#define MAX_NOTES_LEN 100


typedef enum {perfect,good,bad} Mood;
typedef enum {at_home,not_at_home} Location;
typedef enum {True=1,False=0} Bool;



typedef struct SleepEntry {
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
    struct SleepEntry *next;
    struct SleepEntry *previous;
} SleepEntry;


#endif