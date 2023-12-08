#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "table.h"


void listTableData() {
    //loadTablesFromFile();
    char tableName[MAX_STRING_LENGTH];
    int tableIndex = -1;

    printf("Digite o nome da tabela para listar os dados: ");
    scanf("%s", tableName);

    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i].name, tableName) == 0) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }

    printf("\n=== Dados da Tabela %s ===\n", tableName);

    // Exibir cabeçalho da tabela
    for (int i = 0; i < tables[tableIndex].numColumns; i++) {
        printf("%s\t", tables[tableIndex].columns[i].name);
    }
    printf("\n");

    // Exibir registros da tabela
    for (int i = 0; i < tables[tableIndex].numRecords; i++) {
        for (int j = 0; j < tables[tableIndex].numColumns; j++) {
            if (j == 0) {
                printf("%d\t", tables[tableIndex].records[i].primaryKey);
            } else {
                if (strcmp(tables[tableIndex].columns[j].type, "int") == 0) {
                    printf("%d\t", tables[tableIndex].records[i].o_records[i][j].intValue);
                } else if (strcmp(tables[tableIndex].columns[j].type, "char") == 0) {
                    printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                } else if (strcmp(tables[tableIndex].columns[j].type, "float") == 0) {
                    printf("%0.2f\t", tables[tableIndex].records[i].o_records[i][j].floatValue);
                } else if (strcmp(tables[tableIndex].columns[j].type, "double") == 0) {
                    printf("%0.2lf\t", tables[tableIndex].records[i].o_records[i][j].doubleValue);
                }  else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                    printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                }
            }
        }
        printf("\n");
    }
}

void listTables() {
    //loadTablesFromFile();
    printf("\n=== Lista de Tabelas ===\n");

    for (int i = 0; i < numTables; i++) {
        printf("\n=== Tabela %s ===\n", tables[i].name);
        
        for (int l = 0; l < tables[i].numColumns; l++) {
            if (l == 0) {
                printf("%s  ", tables[i].columns[l].name);
            } else {
                printf("%s\t", tables[i].columns[l].name);
            }
        }
        printf("\n");

        // Exibir registros da tabela
        for (int j = 0; j < tables[i].numRecords; j++) {
            for (int k = 0; k < tables[i].numColumns; k++) {
                if (k == 0) {
                    printf("%d   ", tables[i].records[j].primaryKey);
                } else {
                    if (strcmp(tables[i].columns[k].type, "int") == 0) {
                        printf("%d\t",tables[i].records[j].o_records[j][k].intValue);
                    } else if (strcmp(tables[i].columns[k].type, "char") == 0) {
                        printf("%s\t",tables[i].records[j].o_records[j][k].stringValue);
                    } else if (strcmp(tables[i].columns[k].type, "float") == 0) {
                        printf("%0.2f\t",tables[i].records[j].o_records[j][k].floatValue);
                    } else if (strcmp(tables[i].columns[k].type, "double") == 0) {
                        printf("%0.2lf\t",tables[i].records[j].o_records[j][k].doubleValue);
                    } else if (strcmp(tables[i].columns[k].type, "string") == 0) {
                        printf("%s\t",tables[i].records[j].o_records[j][k].stringValue);
                    }
                }
            }
            printf("\n");
        }
    }
}

void createTable() {
    if (numTables >= MAX_TABLES) {
        printf("Número máximo de tabelas atingido.\n");
        return;
    }

    printf("Digite o nome da tabela: ");
    scanf("%s", tables[numTables].name);

    printf("Quantas colunas a tabela terá? ");
    scanf("%d", &tables[numTables].numColumns);

    for (int i = 0; i < tables[numTables].numColumns; i++) {
        if (i == 0) {
            char tipo[MAX_STRING_LENGTH] = "int";
            printf("Digite o nome da coluna chave primária (inteiro sem sinal): ");
            scanf("%s", tables[numTables].columns[i].name);
            strcpy(tables[numTables].columns[i].type, tipo);
        } else {
            printf("Nome da coluna %d: ", i + 1);
            scanf("%s", tables[numTables].columns[i].name);

            printf("Tipo de dado da coluna %d (char, int, float, double, string): ", i + 1);
            scanf("%s", tables[numTables].columns[i].type);
        }
    }

    numTables++;
    saveTablesToFile();
    printf("Tabela criada com sucesso.\n");
    
    printf("\nVoltar ao Menu Principal?\n1. Sim\n2. Não\n");
    int choice_inicio;
    printf("Escolha uma opção: ");
    scanf("%d", &choice_inicio);
    if(choice_inicio == 1){
        system("cls");
        printf("Voltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    } else if (choice_inicio == 2){
        system("cls");
        createTable();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }

}

void insertRecord() {
    char tableName[MAX_STRING_LENGTH];
    int tableIndex = -1;

    printf("Digite o nome da tabela para inserir o registro: ");
    scanf("%s", tableName);

    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i].name, tableName) == 0) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }

    if (tables[tableIndex].numRecords >= MAX_RECORDS) {
        printf("Número máximo de registros atingido para esta tabela.\n");
        return;
    }

    printf("Inserindo registro na tabela %s:\n", tableName);

    int aux = tables[tableIndex].numRecords;

    // Pede ao usuário para fornecer valores para cada coluna
    for (int i = 0; i < tables[tableIndex].numColumns; i++) {

        printf("Digite o valor para a coluna %s (%s): ", tables[tableIndex].columns[i].name, tables[tableIndex].columns[i].type);

        if (i == 0) {
            scanf("%d", &tables[tableIndex].records[tables[tableIndex].numRecords].primaryKey);
            for (int j = (tables[tableIndex].numRecords)-1; j >= 0; j--) {
                if (tables[tableIndex].records[tables[tableIndex].numRecords].primaryKey == tables[tableIndex].records[j].primaryKey) {
                    printf("Chave primária já existe");
                    return;
                }
            }
        } else {
            if (strcmp(tables[tableIndex].columns[i].type, "int") == 0) {
                scanf("%d", (int*)&tables[tableIndex].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[tableIndex].columns[i].type, "char") == 0) {
                scanf(" %c", (char*)&tables[tableIndex].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[tableIndex].columns[i].type, "float") == 0) {
                scanf("%f", (float*)&tables[tableIndex].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[tableIndex].columns[i].type, "double") == 0) {
                scanf("%lf", (double*)&tables[tableIndex].records[aux].o_records[i]);
            } else if (strcmp(tables[tableIndex].columns[i].type, "string") == 0) {
                scanf(" %s", (char*)&tables[tableIndex].records[aux].o_records[aux][i]);
            } else {
                printf("Tipo de dado não suportado.\n");
                return;
            }
        }        
    }

    tables[tableIndex].numRecords++;
    saveTablesToFile();
    printf("Registro inserido com sucesso.\n");
    
    printf("\nVoltar ao Menu Principal?\n1. Sim\n2. Não\n");
    int choice_inicio;
    printf("Escolha uma opção: ");
    scanf("%d", &choice_inicio);
    if(choice_inicio == 1){
        system("cls");
        printf("Voltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    } else if (choice_inicio == 2){
        system("cls");
        insertRecord();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }
}

void deleteTable() {
    char tableName[MAX_STRING_LENGTH];

    printf("Digite o nome da tabela a ser apagada: ");
    scanf("%s", tableName);

    int tableIndex = -1;

    // Encontrar a tabela pelo nome
    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i].name, tableName) == 0) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }

    // Remover a tabela da lista
    for (int i = tableIndex; i < numTables - 1; i++) {
        tables[i] = tables[i + 1];
    }

    // Decrementar o número de tabelas
    numTables--;

    saveTablesToFile();
    printf("Tabela apagada com sucesso.\n");
    
    printf("\nVoltar ao Menu Principal?\n1. Sim\n2. Não\n");
    int choice_inicio;
    printf("Escolha uma opção: ");
    scanf("%d", &choice_inicio);
    if(choice_inicio == 1){
        system("cls");
        printf("Voltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    } else if (choice_inicio == 2){
        system("cls");
        deleteTable();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }
}

void deleteRecord() {
    char tableName[MAX_STRING_LENGTH];
    int primaryKey;

    printf("Digite o nome da tabela para apagar o registro: ");
    scanf("%s", tableName);

    int tableIndex = -1;

    // Encontrar a tabela pelo nome
    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i].name, tableName) == 0) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }


    printf("Digite a chave primária da linha a ser apagada (inteiro sem sinal): ");
    scanf("%d", &primaryKey);

    // Encontrar a linha pelo valor da chave primária
    int rowIndex = -1;
    for (int i = 0; i < tables[tableIndex].numRecords; i++) {
        if (primaryKey == tables[tableIndex].records[i].primaryKey) {
            rowIndex = i;
            break;            
        }
    }

    if (rowIndex == -1) {
        printf("Registro com a chave primária fornecida não encontrado.\n");
        return;
    }

    // Remover a linha
    for (int i = rowIndex; i < tables[tableIndex].numRecords - 1; i++) {
        for (int j = 0; j < tables[tableIndex].numColumns; j++) {
            if (j==0) {
                tables[tableIndex].records[i].primaryKey = tables[tableIndex].records[i+1].primaryKey;
            } else {
                if (strcmp(tables[tableIndex].columns[j].type, "int") == 0) {
                    tables[tableIndex].records[i].o_records[i][j].intValue = tables[tableIndex].records[i+1].o_records[i+1][j].intValue;
                } else if (strcmp(tables[tableIndex].columns[j].type, "char") == 0) {
                    strcpy(tables[tableIndex].records[i].o_records[i][j].stringValue, tables[tableIndex].records[i+1].o_records[i+1][j].stringValue);
                } else if (strcmp(tables[tableIndex].columns[j].type, "float") == 0) {
                    tables[tableIndex].records[i].o_records[i][j].floatValue = tables[tableIndex].records[i+1].o_records[i+1][j].floatValue;
                } else if (strcmp(tables[tableIndex].columns[j].type, "double") == 0) {
                    tables[tableIndex].records[i].o_records[i][j].doubleValue = tables[tableIndex].records[i+1].o_records[i+1][j].doubleValue;
                } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                    strcpy(tables[tableIndex].records[i].o_records[i][j].stringValue, tables[tableIndex].records[i+1].o_records[i+1][j].stringValue);
                }
            }
        }
    }

    // Decrementar o número de registros
    tables[tableIndex].numRecords--;

    saveTablesToFile();
    printf("Registro apagado com sucesso.\n");
    
    printf("\nVoltar ao Menu Principal?\n1. Sim\n2. Não\n");
    printf("Escolha uma opção: ");
    int choice_inicio;
    scanf("%d", &choice_inicio);
    if(choice_inicio == 1){
        system("cls");
        printf("Voltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    } else if (choice_inicio == 2){
        system("cls");
        deleteRecord();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }
}

