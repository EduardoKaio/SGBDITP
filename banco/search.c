#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "search.h"

void searchValue() {
    char table_name[MAX_STRING_LENGTH];
    int table_index = -1;

    printf("Digite o nome da tabela para realizar a pesquisa: ");
    scanf("%s", table_name);

    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, table_name) == 0) {
            table_index = i;
            break;
        }
    }

    if (table_index == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }

    // Exibir colunas disponíveis
    printf("Colunas disponíveis na tabela %s:\n", table_name);
    for (int i = 0; i < tables[table_index].num_columns; i++) {
        printf("%d. %s\n", i + 1, tables[table_index].columns[i].name);
    }

    int column_choice;
    printf("Escolha o número da coluna para pesquisa: ");
    scanf("%d", &column_choice);
    
    if (column_choice==1){
        printf("Digite o valor para pesquisa: ");
        
        int search_value;
        scanf("%d", &search_value);

        // Lógica de pesquisa para valores inteiros
        printf("Resultados da pesquisa:\n");
        printf("\n=== Dados da Tabela %s ===\n", table_name);

        // Exibir cabeçalho da tabela
        for (int i = 0; i < tables[table_index].num_columns; i++) {
            printf("%s\t", tables[table_index].columns[i].name);
        }
        printf("\n");
        
        for (int i = 0; i < tables[table_index].num_records; i++) {
            if (tables[table_index].records[i].primary_key == search_value) {
                printf("\n");
                for (int j = 0; j < tables[table_index].num_columns; j++) {
                    if (j==0) {
                        printf("%d\t", tables[table_index].records[i].primary_key);
                    } else {
                    
                        if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                            printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                        } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                            printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                        } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                            printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                        } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                            printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                        } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                            printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                        }
                    }
                }
                printf("\n");
            }
        }
    } else { 
    
        if (column_choice < 1 || column_choice > tables[table_index].num_columns) {
            printf("Opção inválida.\n");
            return;
        }

        // Obter o tipo da coluna escolhida
        char column_type[MAX_STRING_LENGTH];
        strcpy(column_type, tables[table_index].columns[column_choice - 1].type);

        // Solicitar o valor para pesquisa
        printf("Digite o valor para pesquisa: ");

        if (strcmp(column_type, "int") == 0) {
            int search_value;
            scanf("%d", &search_value);

            // Lógica de pesquisa para valores inteiros
            printf("Resultados da pesquisa:\n");
            printf("\n=== Dados da Tabela %s ===\n", table_name);

            // Exibir cabeçalho da tabela
            for (int i = 0; i < tables[table_index].num_columns; i++) {
                printf("%s\t", tables[table_index].columns[i].name);
            }
            printf("\n");

            for (int i = 0; i < tables[table_index].num_records; i++) {
                if (tables[table_index].records[i].o_records[i][column_choice - 1].int_value == search_value) {
                    for (int j = 0; j < tables[table_index].num_columns; j++) {
                        if (j==0)
                        {
                            printf("%d\t", tables[table_index].records[i].primary_key);
                        } else {
                        
                            if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(column_type, "char") == 0) {
            char search_value[MAX_STRING_LENGTH];
            scanf("%s", search_value);

            // Lógica de pesquisa para strings
            printf("Resultados da pesquisa:\n");
            printf("\n=== Dados da Tabela %s ===\n", table_name);

            // Exibir cabeçalho da tabela
            for (int i = 0; i < tables[table_index].num_columns; i++) {
                printf("%s\t", tables[table_index].columns[i].name);
            }
            printf("\n");

            for (int i = 0; i < tables[table_index].num_records; i++) {
                if (strcmp(tables[table_index].records[i].o_records[i][column_choice - 1].string_value, search_value) == 0) {
                    for (int j = 0; j < tables[table_index].num_columns; j++) {
                        if (j==0)
                        {
                            printf("%d\t", tables[table_index].records[i].primary_key);
                        } else {
                        
                            if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(column_type, "float") == 0) {
            float search_value;
            scanf("%f", &search_value);

            // Lógica de pesquisa para valores float
            printf("Resultados da pesquisa:\n");

            printf("\n=== Dados da Tabela %s ===\n", table_name);

            // Exibir cabeçalho da tabela
            for (int i = 0; i < tables[table_index].num_columns; i++) {
                printf("%s\t", tables[table_index].columns[i].name);
            }
            printf("\n");

            for (int i = 0; i < tables[table_index].num_records; i++) {
                if (tables[table_index].records[i].o_records[i][column_choice - 1].float_value == search_value) {
                    for (int j = 0; j < tables[table_index].num_columns; j++) {
                        if (j==0)
                        {
                            printf("%d\t", tables[table_index].records[i].primary_key);
                        } else {
                        
                            if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(column_type, "double") == 0) {
            double search_value;
            scanf("%lf", &search_value);

            // Lógica de pesquisa para valores double
            printf("Resultados da pesquisa:\n");

            printf("\n=== Dados da Tabela %s ===\n", table_name);

            // Exibir cabeçalho da tabela
            for (int i = 0; i < tables[table_index].num_columns; i++) {
                printf("%s\t", tables[table_index].columns[i].name);
            }
            printf("\n");
            
            for (int i = 0; i < tables[table_index].num_records; i++) {
                if (tables[table_index].records[i].o_records[i][column_choice - 1].double_value == search_value) {
                    for (int j = 0; j < tables[table_index].num_columns; j++) {
                        if (j==0)
                        {
                            printf("%d\t", tables[table_index].records[i].primary_key);
                        } else {
                        
                            if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                            } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        } else if (strcmp(column_type, "string") == 0) {
            char search_value[MAX_STRING_LENGTH];
            scanf("%s", search_value);

            // Opções de pesquisa para strings
            printf("Opções de pesquisa para strings:\n");
            printf("1. Valores maiores que %s\n", search_value);
            printf("2. Valores maiores ou iguais a %s\n", search_value);
            printf("3. Valores iguais a %s\n", search_value);
            printf("4. Valores menores que %s\n", search_value);
            printf("5. Valores menores ou iguais a %s\n", search_value);
            printf("6. Valores próximos a %s\n", search_value);

            int search_option;
            printf("Escolha a opção de pesquisa: ");
            scanf("%d", &search_option);

            // Lógica de pesquisa para strings com as opções escolhidas
            int results_count = 0;
            printf("Resultados da pesquisa:\n");

            printf("\n=== Dados da Tabela %s ===\n", table_name);

            // Exibir cabeçalho da tabela
            for (int i = 0; i < tables[table_index].num_columns; i++) {
                printf("%s\t", tables[table_index].columns[i].name);
            }
            printf("\n");

            for (int i = 0; i < tables[table_index].num_records; i++) {               
                char table_value[MAX_STRING_LENGTH];
                strcpy(table_value, tables[table_index].records[i].o_records[i][column_choice - 1].string_value);

                for (int k = 0; k < strlen(table_value); k++) {
                    table_value[k] = toupper(table_value[k]);
                }
                
                for (int k = 0; k < strlen(search_value); k++) {
                    search_value[k] = toupper(search_value[k]);
                }

                int compare_result = strcmp(table_value, search_value);

                // Implementar lógica de comparação com base na opção escolhida
                switch (search_option) {
                    case 1:
                        if (compare_result > 0) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {
                                
                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 2:
                        if (compare_result >= 0) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {
                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 3:
                        if (compare_result == 0) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {

                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 4:
                        if (compare_result < 0) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {
                                
                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 5:
                        if (compare_result <= 0) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {
                                
                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
                    case 6:
                        if (strstr(table_value, search_value) != NULL) {
                            results_count++;
                            // Exibir o registro correspondente
                            for (int j = 0; j < tables[table_index].num_columns; j++) {
                                
                                if (j==0)
                                {
                                    printf("%d\t", tables[table_index].records[i].primary_key);    
                                } else {
                                
                                    if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                                        printf("%d\t", tables[table_index].records[i].o_records[i][j].int_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                                        printf("%0.2f\t", tables[table_index].records[i].o_records[i][j].float_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                                        printf("%0.2lf\t", tables[table_index].records[i].o_records[i][j].double_value);
                                    } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                                        printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
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
            if (results_count == 0) {
                printf("Nenhum resultado encontrado.\n");
            }
        } else {
            printf("Tipo de dado não suportado.\n");
            return;
        }
    }
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
        searchValue();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }
}