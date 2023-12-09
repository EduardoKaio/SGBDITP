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
    int primaryKey;
    union {
        int intValue;
        char stringValue[MAX_STRING_LENGTH];
        float floatValue;
        double doubleValue;
    } o_records[MAX_RECORDS][MAX_COLUMNS];
} Records;

typedef struct {
    char name[MAX_STRING_LENGTH];
    Column columns[MAX_COLUMNS];
    int numColumns;
    Records records[MAX_RECORDS];
    int numRecords;
} Table;

extern Table tables[MAX_TABLES];
extern int numTables;

void createTable();
void insertRecord();
void listTables();
void listTableData();
void deleteTable();
void deleteRecord();

#endif
