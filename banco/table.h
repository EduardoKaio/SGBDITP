#ifndef TABLE_H
#define TABLE_H

#include "file.h"


#define MAX_TABLES 100
#define MAX_STRING_LENGTH 50
#define MAX_COLUMNS 10
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    char type[MAX_STRING_LENGTH];
} Column;

typedef struct {
    int primary_key;
    union {
        int int_value;
        char string_value[MAX_STRING_LENGTH];
        float float_value;
        double double_value;
    } o_records[MAX_RECORDS][MAX_COLUMNS];
} Records;

typedef struct {
    char name[MAX_STRING_LENGTH];
    Column columns[MAX_COLUMNS];
    int num_columns;
    Records records[MAX_RECORDS];
    int num_records;
} Table;

extern Table tables[MAX_TABLES];
extern int num_tables;

void createTable();
void insertRecord();
void listTables();
void listTableData();
void deleteTable();
void deleteRecord();

#endif
