#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "search.h"

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