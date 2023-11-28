#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{

    int opcao;

    do
    {
        printf("Escolha uma opção:\n"
               "1 ---- Criar uma nova tabela\n"
               "2 ---- Criar uma nova linha na tabela\n"
               "3 ---- Pesquisar valor em uma tabela\n"
               "4 ---- Listar todas as tabelas\n"
               "5 ---- Listar todos os dados de uma tabela\n"
               "6 ---- Apagar uma tabela\n"
               "7 ---- Apagar uma linha de uma tabela\n"
               "0 ---- Sair \n"

        );

        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            criarTabela();
            break;
        
        case 2:
            char nome_tabela[20]; //exemplo
            fgets(nome_tabela, 21, stdin);
            
            criarNovaLinha();
            break;
        
        case 3:
            char nome_tabela[20]; //exemplo
            fgets(nome_tabela, 21, stdin);
            
            pesquisarDado();
            break;
        
        case 4:
            listarTabelas();
            break;
        
        case 5:
            char nome_tabela[20]; //exemplo
            fgets(nome_tabela, 21, stdin);
            
            listarDados();
            break;
        
        case 6:
            char nome_tabela[20]; //exemplo
            fgets(nome_tabela, 21, stdin);
            
            apagarTabela(nome_tabela);
            
            break;
        
        case 7:
            char nome_tabela[20]; //exemplo
            int chave_primaria;

            fgets(nome_tabela, 21, stdin);
            scanf("%i", chave_primaria);

            apagarLinha();
            break;
        
        case 0:
            break;

        default:
            printf("Selecione uma opção válida");
            break;
        }

    } while (opcao != 0);

    return 0;
}