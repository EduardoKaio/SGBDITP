#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "search.h"
#include "file.h"

Table tables[MAX_TABLES];
int numTables = 0;

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