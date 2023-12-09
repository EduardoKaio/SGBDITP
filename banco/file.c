#include <stdio.h>
#include "file.h"
#include "table.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void saveTablesToFile() {
    FILE *file = fopen("tables.txt", "w");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numTables; i++) {
        fprintf(file, "%s %d\n", tables[i].name, tables[i].numColumns);

        for (int j = 0; j < tables[i].numColumns; j++) {
            fprintf(file, "%s %s\n", tables[i].columns[j].name, tables[i].columns[j].type);
        }

        for (int j = 0; j < tables[i].numRecords; j++) {
            for (int k = 0; k < tables[i].numColumns; k++) {

                if (k == 0) {
                    fprintf(file, "%d ", tables[i].records[j].primaryKey);
                } else {
                    if (strcmp(tables[i].columns[k].type, "int") == 0) {
                        fprintf(file, "%d ", tables[i].records[j].o_records[j][k].intValue);
                    } else if (strcmp(tables[i].columns[k].type, "char") == 0) {
                        fprintf(file, "%s ", tables[i].records[j].o_records[j][k].stringValue);
                    } else if (strcmp(tables[i].columns[k].type, "float") == 0) {
                        fprintf(file, "%f ", tables[i].records[j].o_records[j][k].floatValue);
                    } else if (strcmp(tables[i].columns[k].type, "double") == 0) {
                        fprintf(file, "%lf ", tables[i].records[j].o_records[j][k].doubleValue);
                    }   else if (strcmp(tables[i].columns[k].type, "string") == 0) {
                        fprintf(file, "%s ", tables[i].records[j].o_records[j][k].stringValue);
                    } else {
                        fprintf(file, "Tipo não suportado ");
                    }
                }
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

void loadTablesFromFile() {
    FILE *file = fopen("tables.txt", "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", tables[numTables].name, &tables[numTables].numColumns) == 2) {
        for (int i = 0; i < tables[numTables].numColumns; i++) {
            fscanf(file, "%s %s", tables[numTables].columns[i].name, tables[numTables].columns[i].type);
        }

        // Carregar registros da tabela
        tables[numTables].numRecords = 0; // Resetar o número de registros

        while (fscanf(file, "%d ", &tables[numTables].records[tables[numTables].numRecords].primaryKey) == 1) {
            for (int i = 1; i < tables[numTables].numColumns; i++) {
                if (strcmp(tables[numTables].columns[i].type, "int") == 0) {
                    fscanf(file, "%d ", &tables[numTables].records[tables[numTables].numRecords].o_records[tables[numTables].numRecords][i].intValue);
                } else if (strcmp(tables[numTables].columns[i].type, "char") == 0) {
                    fscanf(file, "%s ", tables[numTables].records[tables[numTables].numRecords].o_records[tables[numTables].numRecords][i].stringValue);
                } else if (strcmp(tables[numTables].columns[i].type, "float") == 0) {
                    fscanf(file, "%f ", &tables[numTables].records[tables[numTables].numRecords].o_records[tables[numTables].numRecords][i].floatValue);
                } else if (strcmp(tables[numTables].columns[i].type, "double") == 0) {
                    fscanf(file, "%lf ", &tables[numTables].records[tables[numTables].numRecords].o_records[tables[numTables].numRecords][i].doubleValue);
                } else if (strcmp(tables[numTables].columns[i].type, "string") == 0) {
                    fscanf(file, "%s ", tables[numTables].records[tables[numTables].numRecords].o_records[tables[numTables].numRecords][i].stringValue);
                }
            }

            tables[numTables].numRecords++;
        }

        // printf("%d\n", numTables);
        numTables++;
    }

    fclose(file);
}   

void cleanupAndSave() {
    saveTablesToFile();
    // ... (liberar outros recursos, se necessário)
}