#ifndef DATABASE_H
#define DATABASE_H
#define READ_FILE_LINE_LEN 200


// Functions
Bool check_db_filepath(const char *db_filepath);
Bool read_db(const char *db_filepath);
Bool show_all_entries(const char *db_filepath);

#endif