#include <stdio.h>
#include "file.h"
#include "table.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função de salvar as tabelas no arquivo
void saveTablesToFile() {
    FILE *file = fopen("tables.txt", "w");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Escrita dos dados no arquivo
    for (int i = 0; i < num_tables; i++) {
        fprintf(file, "%s %d\n", tables[i].name, tables[i].num_columns);

        for (int j = 0; j < tables[i].num_columns; j++) {
            fprintf(file, "%s %s\n", tables[i].columns[j].name, tables[i].columns[j].type);
        }

        for (int j = 0; j < tables[i].num_records; j++) {
            for (int k = 0; k < tables[i].num_columns; k++) {

                if (k == 0) {
                    fprintf(file, "%d ", tables[i].records[j].primary_key);
                } else {
                    if (strcmp(tables[i].columns[k].type, "int") == 0) {
                        fprintf(file, "%d ", tables[i].records[j].o_records[j][k].int_value);
                    } else if (strcmp(tables[i].columns[k].type, "char") == 0) {
                        fprintf(file, "%s ", tables[i].records[j].o_records[j][k].string_value);
                    } else if (strcmp(tables[i].columns[k].type, "float") == 0) {
                        fprintf(file, "%f ", tables[i].records[j].o_records[j][k].float_value);
                    } else if (strcmp(tables[i].columns[k].type, "double") == 0) {
                        fprintf(file, "%lf ", tables[i].records[j].o_records[j][k].double_value);
                    }   else if (strcmp(tables[i].columns[k].type, "string") == 0) {
                        fprintf(file, "%s ", tables[i].records[j].o_records[j][k].string_value);
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

// Função para ler os dados do arquivo
void loadTablesFromFile() {
    FILE *file = fopen("tables.txt", "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Leitura dos dados do arquivo
    while (fscanf(file, "%s %d", tables[num_tables].name, &tables[num_tables].num_columns) == 2) {
        for (int i = 0; i < tables[num_tables].num_columns; i++) {
            fscanf(file, "%s %s", tables[num_tables].columns[i].name, tables[num_tables].columns[i].type);
        }

        // Carregar registros da tabela
        tables[num_tables].num_records = 0; // Resetar o número de registros

        while (fscanf(file, "%d ", &tables[num_tables].records[tables[num_tables].num_records].primary_key) == 1) {
            for (int i = 1; i < tables[num_tables].num_columns; i++) {
                if (strcmp(tables[num_tables].columns[i].type, "int") == 0) {
                    fscanf(file, "%d ", &tables[num_tables].records[tables[num_tables].num_records].o_records[tables[num_tables].num_records][i].int_value);
                } else if (strcmp(tables[num_tables].columns[i].type, "char") == 0) {
                    fscanf(file, "%s ", tables[num_tables].records[tables[num_tables].num_records].o_records[tables[num_tables].num_records][i].string_value);
                } else if (strcmp(tables[num_tables].columns[i].type, "float") == 0) {
                    fscanf(file, "%f ", &tables[num_tables].records[tables[num_tables].num_records].o_records[tables[num_tables].num_records][i].float_value);
                } else if (strcmp(tables[num_tables].columns[i].type, "double") == 0) {
                    fscanf(file, "%lf ", &tables[num_tables].records[tables[num_tables].num_records].o_records[tables[num_tables].num_records][i].double_value);
                } else if (strcmp(tables[num_tables].columns[i].type, "string") == 0) {
                    fscanf(file, "%s ", tables[num_tables].records[tables[num_tables].num_records].o_records[tables[num_tables].num_records][i].string_value);
                }
            }

            tables[num_tables].num_records++;
        }

        num_tables++;
    }

    fclose(file);
}   

void cleanupAndSave() {
    saveTablesToFile();
    // ... (liberar outros recursos, se necessário)
}