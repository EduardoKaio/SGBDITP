#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TABLES 100
#define MAX_COLUMNS 10
#define MAX_STRING_LENGTH 50
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    char type[MAX_STRING_LENGTH];
} Column;

typedef struct
{
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

Table tables[MAX_TABLES];
int numTables = 0;

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

        printf("%d\n", numTables);
        numTables++;
    }

    fclose(file);
}

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
}

void searchValue() {
    char tableName[MAX_STRING_LENGTH];
    int tableIndex = -1;

    printf("Digite o nome da tabela para realizar a pesquisa: ");
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

    // Exibir colunas disponíveis
    printf("Colunas disponíveis na tabela %s:\n", tableName);
    for (int i = 0; i < tables[tableIndex].numColumns; i++) {
        printf("%d. %s\n", i + 1, tables[tableIndex].columns[i].name);
    }

    int columnChoice;
    printf("Escolha o número da coluna para pesquisa: ");
    scanf("%d", &columnChoice);
    
    if (columnChoice==1){
        printf("Digite o valor para pesquisa: ");
        
        int searchValue;
        scanf("%d", &searchValue);

        // Lógica de pesquisa para valores inteiros
        printf("Resultados da pesquisa:\n");
        for (int i = 0; i < tables[tableIndex].numRecords; i++) {
            if (tables[tableIndex].records[i].primaryKey == searchValue) {
                // Exibir a linha que corresponde ao valor pesquisado
                for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                    if (j==0) {
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
                        } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                            printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                        }
                    }
                }
                printf("\n");
            }
        }
    } else { 
    
        if (columnChoice < 1 || columnChoice > tables[tableIndex].numColumns) {
            printf("Opção inválida.\n");
            return;
        }

        // Obter o tipo da coluna escolhida
        char columnType[MAX_STRING_LENGTH];
        strcpy(columnType, tables[tableIndex].columns[columnChoice - 1].type);

        // Solicitar o valor para pesquisa
        printf("Digite o valor para pesquisa: ");

        if (strcmp(columnType, "int") == 0) {
            int searchValue;
            scanf("%d", &searchValue);

            // Lógica de pesquisa para valores inteiros
            printf("Resultados da pesquisa:\n");
            for (int i = 0; i < tables[tableIndex].numRecords; i++) {
                if (tables[tableIndex].records[i].o_records[i][columnChoice - 1].intValue == searchValue) {
                    // Exibir a linha que corresponde ao valor pesquisado
                    for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                        if (j==0)
                        {
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
                            } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(columnType, "char") == 0) {
            char searchValue[MAX_STRING_LENGTH];
            scanf("%s", searchValue);

            // Lógica de pesquisa para strings
            printf("Resultados da pesquisa:\n");
            for (int i = 0; i < tables[tableIndex].numRecords; i++) {
                if (strcmp(tables[tableIndex].records[i].o_records[i][columnChoice - 1].stringValue, searchValue) == 0) {
                    // Exibir a linha que corresponde ao valor pesquisado
                    for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                        if (j==0)
                        {
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
                            } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(columnType, "float") == 0) {
            float searchValue;
            scanf("%f", &searchValue);

            // Lógica de pesquisa para valores float
            printf("Resultados da pesquisa:\n");
            for (int i = 0; i < tables[tableIndex].numRecords; i++) {
                if (tables[tableIndex].records[i].o_records[i][columnChoice - 1].floatValue == searchValue) {
                    // Exibir a linha que corresponde ao valor pesquisado
                    for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                        if (j==0)
                        {
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
                            } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(columnType, "double") == 0) {
            double searchValue;
            scanf("%lf", &searchValue);

            // Lógica de pesquisa para valores double
            printf("Resultados da pesquisa:\n");
            for (int i = 0; i < tables[tableIndex].numRecords; i++) {
                if (tables[tableIndex].records[i].o_records[i][columnChoice - 1].doubleValue == searchValue) {
                    // Exibir a linha que corresponde ao valor pesquisado
                    for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                        if (j==0)
                        {
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
                            } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(columnType, "string") == 0) {
            char searchValue[MAX_STRING_LENGTH];
            scanf("%s", searchValue);

            // Opções de pesquisa para strings
            printf("Opções de pesquisa para strings:\n");
            printf("1. Valores maiores que %s\n", searchValue);
            printf("2. Valores maiores ou iguais a %s\n", searchValue);
            printf("3. Valores iguais a %s\n", searchValue);
            printf("4. Valores menores que %s\n", searchValue);
            printf("5. Valores menores ou iguais a %s\n", searchValue);
            printf("6. Valores próximos a %s\n", searchValue);

            int searchOption;
            printf("Escolha a opção de pesquisa: ");
            scanf("%d", &searchOption);

            // Lógica de pesquisa para strings com as opções escolhidas
            int resultsCount = 0;
            printf("Resultados da pesquisa:\n");
            for (int i = 0; i < tables[tableIndex].numRecords; i++) {               
                char tableValue[MAX_STRING_LENGTH];
                strcpy(tableValue, tables[tableIndex].records[i].o_records[i][columnChoice - 1].stringValue);

                for (int k = 0; k < strlen(tableValue); k++) {
                    tableValue[k] = toupper(tableValue[k]);
                }
                
                for (int k = 0; k < strlen(searchValue); k++) {
                    searchValue[k] = toupper(searchValue[k]);
                }

                int compareResult = strcmp(tableValue, searchValue);

                // Implementar lógica de comparação com base na opção escolhida
                switch (searchOption) {
                    case 1:
                        if (compareResult > 0) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 2:
                        if (compareResult >= 0) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 3:
                        if (compareResult == 0) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 4:
                        if (compareResult < 0) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 5:
                        if (compareResult <= 0) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 6:
                        if (strstr(tableValue, searchValue) != NULL) {
                            resultsCount++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[tableIndex].numColumns; j++) {
                                if (j==0)
                                {
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
                                    } else if (strcmp(tables[tableIndex].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[tableIndex].records[i].o_records[i][j].stringValue);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    default:
                        printf("Opção de pesquisa inválida.\n");
                        return;
                }
            }
            if (resultsCount == 0) {
                printf("Nenhum resultado encontrado.\n");
            }
        } else {
            printf("Tipo de dado não suportado.\n");
            return;
        }
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
}


void cleanupAndSave() {
    saveTablesToFile();
    // ... (liberar outros recursos, se necessário)
}

int main() {
    atexit(cleanupAndSave);
    loadTablesFromFile();

    int choice;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Criar Tabela\n");
        printf("2. Listar Tabelas\n");
        printf("3. Inserir Registro\n");
        printf("4. Listar Dados da Tabela\n");
        printf("5. Pesquisar Valor\n");
        printf("6. Apagar Registro\n");
        printf("7. Apagar Tabela\n");
        printf("8. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createTable();
                break;
            case 2:
                listTables();
                break;
            case 3:
                insertRecord();
                break;
            case 4:
                listTableData();
                break;
            case 5:
                searchValue();
                break;
            case 6:
                deleteRecord();
                break;
            case 7:
                deleteTable();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 8);

    return 0;
}