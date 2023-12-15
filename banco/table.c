#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "table.h"

// Função para listar os dados de uma tabela específica
void listTableData() {
    char table_name[MAX_STRING_LENGTH];
    int table_index = -1;

    printf("Digite o nome da tabela para listar os dados: ");
    scanf("%s", table_name);

    // Verificar se a tabela existe
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, table_name) == 0) {
            table_index = i;
            break;
        }
    }

    if (table_index == -1) {
        printf("Tabela não encontrada.\n");
        return;
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
            listTableData();
        } else {
            printf("Valor inválido.\nVoltando ao Menu Principal...\n");
            sleep(2);
            system("cls");
            return;
        }
    }

    printf("\n=== Dados da Tabela %s ===\n", table_name);

    // Exibir cabeçalho da tabela
    for (int i = 0; i < tables[table_index].num_columns; i++) {
        printf("%s\t", tables[table_index].columns[i].name);
    }
    printf("\n");

    // Exibir registros da tabela
    for (int i = 0; i < tables[table_index].num_records; i++) {
        for (int j = 0; j < tables[table_index].num_columns; j++) {
            if (j == 0) {
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
                }  else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                    printf("%s\t", tables[table_index].records[i].o_records[i][j].string_value);
                }
            }
        }
        printf("\n");
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
        listTableData();
    } else {
        printf("Valor inválido.\nVoltando ao Menu Principal...\n");
        sleep(2);
        system("cls");
        return;
    }
}

// Função para listar todas as tabelas
void listTables() {
    printf("\n=== Lista de Tabelas ===\n");

    for (int i = 0; i < num_tables; i++) {
        printf("\n=== Tabela %s ===\n", tables[i].name);
        
        //Exibir o cabeçalho de cada tabela
        for (int l = 0; l < tables[i].num_columns; l++) {
            if (l == 0) {
                printf("%s  ", tables[i].columns[l].name);
            } else {
                printf("%s\t", tables[i].columns[l].name);
            }
        }
        printf("\n");

        // Exibir registros da tabela
        for (int j = 0; j < tables[i].num_records; j++) {
            for (int k = 0; k < tables[i].num_columns; k++) {
                if (k == 0) {
                    printf("%d   ", tables[i].records[j].primary_key);
                } else {
                    if (strcmp(tables[i].columns[k].type, "int") == 0) {
                        printf("%d\t",tables[i].records[j].o_records[j][k].int_value);
                    } else if (strcmp(tables[i].columns[k].type, "char") == 0) {
                        printf("%s\t",tables[i].records[j].o_records[j][k].string_value);
                    } else if (strcmp(tables[i].columns[k].type, "float") == 0) {
                        printf("%0.2f\t",tables[i].records[j].o_records[j][k].float_value);
                    } else if (strcmp(tables[i].columns[k].type, "double") == 0) {
                        printf("%0.2lf\t",tables[i].records[j].o_records[j][k].double_value);
                    } else if (strcmp(tables[i].columns[k].type, "string") == 0) {
                        printf("%s\t",tables[i].records[j].o_records[j][k].string_value);
                    }
                }
            }
            printf("\n");
        }
    }
}

// Função para criar uma nova tabela
void createTable() {
    //Verifica se o número de tabelas criadas atingiu o limite estipulado
    if (num_tables >= MAX_TABLES) {
        printf("Número máximo de tabelas atingido.\n");
        return;
    }

    int table_index = -1;

    printf("Digite o nome da tabela que deseja criar: ");
    scanf("%s", tables[num_tables].name);

    //Verifica se a tabela que vai ser criada já existe
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, tables[num_tables].name) == 0) {
            table_index = i;
            break;
        }
    }

    if (table_index != -1) {
        printf("A tabela já Existe.\n");
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

    printf("Quantas colunas a tabela terá? ");
    scanf("%d", &tables[num_tables].num_columns);

    //Ler os nomes e tipos de cada coluna
    for (int i = 0; i < tables[num_tables].num_columns; i++) {
        if (i == 0) {
            char tipo[MAX_STRING_LENGTH] = "int";
            printf("Digite o nome da coluna chave primária: ");
            scanf("%s", tables[num_tables].columns[i].name);
            strcpy(tables[num_tables].columns[i].type, tipo);
        } else {
            printf("Nome da coluna %d: ", i + 1);
            scanf("%s", tables[num_tables].columns[i].name);

            printf("Tipo de dado da coluna %d (char, int, float, double, string): ", i + 1);
            scanf("%s", tables[num_tables].columns[i].type);
        }
    }

    num_tables++;
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

// Função para inserir uma linha em uma tabela
void insertRecord() {
    char table_name[MAX_STRING_LENGTH];
    int table_index = -1;

    printf("Digite o nome da tabela para inserir o registro: ");
    scanf("%s", table_name);

    //Verifica se a tabela existe
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

    //Verifica se o número de linhas criadas já atingiu o máximo estipulado
    if (tables[table_index].num_records >= MAX_RECORDS) {
        printf("Número máximo de registros atingido para esta tabela.\n");
        return;
    }

    printf("Inserindo registro na tabela %s:\n", table_name);

    //Criação de uma variável auxiliar para diminuir o tamanho das próximas variáveis
    int aux = tables[table_index].num_records;

    // Pede ao usuário para fornecer valores para cada coluna
    for (int i = 0; i < tables[table_index].num_columns; i++) {

        printf("Digite o valor para a coluna %s (%s): ", tables[table_index].columns[i].name, tables[table_index].columns[i].type);

        if (i == 0) {
            scanf("%d", &tables[table_index].records[tables[table_index].num_records].primary_key);
            for (int j = (tables[table_index].num_records)-1; j >= 0; j--) {
                if (tables[table_index].records[tables[table_index].num_records].primary_key == tables[table_index].records[j].primary_key) {
                    printf("Chave primária já existe");
                    return;
                }
            }
        } else {
            if (strcmp(tables[table_index].columns[i].type, "int") == 0) {
                scanf("%d", (int*)&tables[table_index].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[table_index].columns[i].type, "char") == 0) {
                scanf(" %c", (char*)&tables[table_index].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[table_index].columns[i].type, "float") == 0) {
                scanf("%f", (float*)&tables[table_index].records[aux].o_records[aux][i]);
            } else if (strcmp(tables[table_index].columns[i].type, "double") == 0) {
                scanf("%lf", (double*)&tables[table_index].records[aux].o_records[i]);
            } else if (strcmp(tables[table_index].columns[i].type, "string") == 0) {
                scanf(" %s", (char*)&tables[table_index].records[aux].o_records[aux][i]);
            } else {
                printf("Tipo de dado não suportado.\n");
                return;
            }
        }        
    }

    tables[table_index].num_records++;
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

// Função para apagar uma tabela
void deleteTable() {
    char table_name[MAX_STRING_LENGTH];

    printf("Digite o nome da tabela a ser apagada: ");
    scanf("%s", table_name);

    int table_index = -1;

    // Verificar se a tabela existe
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, table_name) == 0) {
            table_index = i;
            break;
        }
    }

    if (table_index == -1) {
        printf("Tabela não encontrada.\n");
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

    // Remover a tabela da lista
    for (int i = table_index; i < num_tables - 1; i++) {
        tables[i] = tables[i + 1];
    }

    // Decrementar o número de tabelas
    num_tables--;

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

// Função para apagar uma linha de uma tabela
void deleteRecord() {
    char table_name[MAX_STRING_LENGTH];
    int primary_key;

    printf("Digite o nome da tabela para apagar o registro: ");
    scanf("%s", table_name);

    int table_index = -1;

    // Verificar se a tabela existe
    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, table_name) == 0) {
            table_index = i;
            break;
        }
    }

    if (table_index == -1) {
        printf("Tabela não encontrada.\n");
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
            deleteRecord();
        } else {
            printf("Valor inválido.\nVoltando ao Menu Principal...\n");
            sleep(2);
            system("cls");
            return;
        }
    }


    printf("Digite a chave primária da linha a ser apagada (inteiro sem sinal): ");
    scanf("%d", &primary_key);

    // Encontrar a linha pelo valor da chave primária
    int row_index = -1;
    for (int i = 0; i < tables[table_index].num_records; i++) {
        if (primary_key == tables[table_index].records[i].primary_key) {
            row_index = i;
            break;            
        }
    }

    if (row_index == -1) {
        printf("Registro com a chave primária fornecida não encontrado.\n");
        return;
    }

    // Remover a linha
    for (int i = row_index; i < tables[table_index].num_records - 1; i++) {
        for (int j = 0; j < tables[table_index].num_columns; j++) {
            if (j==0) {
                tables[table_index].records[i].primary_key = tables[table_index].records[i+1].primary_key;
            } else {
                if (strcmp(tables[table_index].columns[j].type, "int") == 0) {
                    tables[table_index].records[i].o_records[i][j].int_value = tables[table_index].records[i+1].o_records[i+1][j].int_value;
                } else if (strcmp(tables[table_index].columns[j].type, "char") == 0) {
                    strcpy(tables[table_index].records[i].o_records[i][j].string_value, tables[table_index].records[i+1].o_records[i+1][j].string_value);
                } else if (strcmp(tables[table_index].columns[j].type, "float") == 0) {
                    tables[table_index].records[i].o_records[i][j].float_value = tables[table_index].records[i+1].o_records[i+1][j].float_value;
                } else if (strcmp(tables[table_index].columns[j].type, "double") == 0) {
                    tables[table_index].records[i].o_records[i][j].double_value = tables[table_index].records[i+1].o_records[i+1][j].double_value;
                } else if (strcmp(tables[table_index].columns[j].type, "string") == 0) {
                    strcpy(tables[table_index].records[i].o_records[i][j].string_value, tables[table_index].records[i+1].o_records[i+1][j].string_value);
                }
            }
        }
    }

    // Decrementar o número de registros
    tables[table_index].num_records--;

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