#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void criarTabela(){

}

void criarNovaLinha(){

}

void pesquisarDado(){

}

void listarTabelas(){

}

void listarDados(){

}

void apagarTabela(char nome_tabela[]){

}

void apagarLinha()  {

}


int main()
{

    int opcao;

    do
    {
        printf("Escolha uma opção:\n"
               "1 - Criar uma nova tabela\n"
               "2 - Criar uma nova linha na tabela\n"
               "3 - Pesquisar valor em uma tabela\n"
               "4 - Listar todas as tabelas\n"
               "5 - Listar todos os dados de uma tabela\n"
               "6 - Apagar uma tabela\n"
               "7 - Apagar uma linha de uma tabela\n"
               "0 - Sair \n"
        );

        scanf("%i", &opcao);
        char nome_tabela[50];

        switch (opcao)
        {
        case 1:
            criarTabela();
            break;
        
        case 2:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 21, stdin);
            criarNovaLinha();
            break;
        
        case 3:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 21, stdin);
            
            pesquisarDado();
            break;
        
        case 4:
            listarTabelas();
            break;
        
        case 5:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 21, stdin);
            
            listarDados();
            break;
        
        case 6:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 21, stdin);
            
            apagarTabela(nome_tabela);
            
            break;
        
        case 7:
            // char nome_tabela[20]; //exemplo
            
            int chave_primaria;
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 21, stdin);
            
            printf("Digite a chave primária da linha: ");
            scanf("%i", &chave_primaria);

            apagarLinha();
            break;
        
        case 0:
            break;

        default:
            printf("Selecione uma opção válida\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}